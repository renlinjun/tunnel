/*******************************************************************************
Copyright (c) 2008-2013, Zhejiang Uniview Technology Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                                    imos_sdk_xml.h
Project Code: imos sdk
Module Name: imos sdk
Date Created: 2011-10-24
Author: chengjian/03354
Description: xml构造解析框架代码，继承自IMOS_ActiveX控件工程，非本次编写代码

--------------------------------------------------------------------------------
Modification History
DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
YYYY-MM-DD

*******************************************************************************/

#ifndef IMOS_SDK_XML_H
#define IMOS_SDK_XML_H

#include "string"
#include "sstream"
#include "vector"
#include "imos_public.h"
#include "libxml/parser.h"
#include "dllimport.h"

#define IMOS_SDK_XML_QUOT "'"

/*lint -save -e* */

/* 标准库容器前置申明 */
namespace std{
    template<class _Ty, class _Ax> class vector;
    template<class _Ty, class _Ax> class list;
    template<class _Ty, class _Ax> class deque;
    template<class _Kty,class _Pr, class _Alloc> class set;
    template<class _Kty,class _Pr, class _Alloc> class multiset;
}

/* 基础工具类 */
namespace IMOS_SDK_XML
{
    namespace UTILITY
    {
        /* true类型 */
        struct TRUE_TYPE{};
        /* false类型 */
        struct FALSE_TYPE{};

        /* 类型选择元函数 */
        template<bool bFlag, class T1, class T2>
        struct SelType
        {
            typedef T1 type;
        };
        template<class T1, class T2>
        struct SelType<false, T1, T2>
        {
            typedef T2 type;
        };

        /* 判断T是否为char类型的元函数 */
        template<class T> struct SIsCharType
        {
            static long test(...);
            static char test(const CHAR *);
            static char test(const UCHAR *);
            enum {value = (sizeof(test((T *)0)) == sizeof(char))};
        };

        /* 判断T是否为内置类型的元函数 */
        template<class T> struct SIsInnerType
        {
            static long test(...);

            #define ADD_INNER_TYPE(type) static char test(type *)

            ADD_INNER_TYPE(CHAR);
            ADD_INNER_TYPE(UCHAR);
            ADD_INNER_TYPE(SHORT);
            ADD_INNER_TYPE(USHORT);
            ADD_INNER_TYPE(LONG_REAL);
            ADD_INNER_TYPE(ULONG_REAL);
#ifndef WIN32
            ADD_INNER_TYPE(LONG_32);
            ADD_INNER_TYPE(ULONG_32);
#endif
			ADD_INNER_TYPE(DLONG);
            ADD_INNER_TYPE(DULONG);
            ADD_INNER_TYPE(std::string);

            ADD_INNER_TYPE(const CHAR);
            ADD_INNER_TYPE(const UCHAR);
            ADD_INNER_TYPE(const SHORT);
            ADD_INNER_TYPE(const USHORT);
#ifndef WIN32
            ADD_INNER_TYPE(const LONG_32);
            ADD_INNER_TYPE(const ULONG_32);
#endif
            ADD_INNER_TYPE(const LONG_REAL);
            ADD_INNER_TYPE(const ULONG_REAL);
            ADD_INNER_TYPE(const DLONG);
            ADD_INNER_TYPE(const DULONG);
            ADD_INNER_TYPE(const std::string);

            enum {value = (sizeof(test((T *)0)) == sizeof(char))};
        };

        /* 判断T是否为stl容器类型的元函数 */
        template<class T> struct SIsContainType
        {
            static long test(...);

            #define ADD_CONTAIN_TYPE(type) template<class V, class A> static char test(type<V, A> *)
            #define ADD_MAP_CONTAIN_TYPE(type) template<class V, class P, class A> static char test(type<V, P, A> *)

            ADD_CONTAIN_TYPE(std::vector);
            ADD_CONTAIN_TYPE(std::list);
            ADD_CONTAIN_TYPE(std::deque);
            ADD_MAP_CONTAIN_TYPE(std::set);
            ADD_MAP_CONTAIN_TYPE(std::multiset);

            enum {value = (sizeof(test((T *)0)) == sizeof(char))};
        };

        /* 判断T是否为内置数组类型的元函数 */
        template<class T> struct SIsArrayType
        {
            static long test(...);
            template<class K, int N> static char test(const K (*)[N]);
            enum {value = (sizeof(test((T *)0)) == sizeof(char))};
        };

        /* 判断T是否为char数组类型的元函数 */
        template<class T> struct SIsCharArrayType
        {
            static long test(...);
            template<int N> static char test(const CHAR (*)[N]);
            template<int N> static char test(const UCHAR (*)[N]);
            enum {value = (sizeof(test((T *)0)) == sizeof(char))};
        };

        /* 获取数组T的子元素类型的元函数 */
        template<class T> struct SArrayInnerType
        {
            template<class K> struct STypeWrapper{
                typedef FALSE_TYPE type;
            };
            template <class E> struct STypeWrapper<E**>{
                typedef E type;
            };
            template <class E, int N> struct STypeWrapper<E(*)[N]>{
                typedef E type;
            };

            typedef typename STypeWrapper<T*>::type type;
        };

        /* 获取指针指向数据的元函数，可以处理多级指针 */
        struct SGetPointToData
        {
            template<class E> struct STypeWrapper{
                typedef E type;
                static type &value(E&v){return v;}
                static bool is_null(E&v){return false;}
            };
            template <class E> struct STypeWrapper<E*>{
                typedef typename STypeWrapper<E>::type type;
                static type &value(E*v){return STypeWrapper<E>::value(*v);}
                static bool is_null(E*v){return (v==NULL) || STypeWrapper<E>::is_null(*v);}
            };
            template <class E> struct STypeWrapper<E* const> : STypeWrapper<E*>{};

            /* 判断是否为空指针 */
            template<class T>
            static bool is_null(T &v)
            {
                return STypeWrapper<T>::is_null(v);
            }

            /* 取得指针指向数据的引用 */
            template<class T>
            static typename STypeWrapper<T>::type &value(T &v)
            {
                return STypeWrapper<T>::value(v);
            }
        };

        /* 空元组 */
        struct NullElement
        {
        };

        /* 字符串或字符数组元组 */
        struct ACElement
        {
            const char *pcEleName;
            const char *pcValue;
            LONG_32 lLen;
        };

        /* 基础类型元组 */
        template<class T> struct SElement
        {
            const char *pcEleName;
            const T *pValue;
        };

        /* 结构类型元组 */
        template<class T> struct MElement
        {
            const char *pcEleName;
            const T* pstValue;
        };

        /* stl容器类型元组 */
        template<class T> struct VContainElement
        {
            enum {isInnerType = SIsInnerType<typename T::value_type>::value};
            const char *pcEleName;
            T *poContain;
        };

        /* 数组类型元组，T为数组元素类型，bIsInType表示T是否为基础类型 */
        template<class T, bool bIsInType> struct VElement
        {
            const char *pcEleName;
            const T* pstValue;
            LONG_32 lCount;
        };

        /* 数组类型元组，T为数组元素类型，bIsInType表示T是否为基础类型 */
        template<class T, bool bIsInType> struct VOutElement
        {
            const char *pcEleName;
            const T* pstValue;
            LONG_32 *plCount;
        };

        /* 数组类型元组 */
        template<class T> struct VMElement
        {
            const char *pcEleName;
            const T* pstValue;
            int index;
        };

        /* 属性元组，继承了元素元组的实现 */
        template<class E> struct Attribute : public E
        {
            Attribute(const E &e) : E(e)
            {
            }
        };

        /* 节点内容元组，继承了元素元组的实现 */
        template<class E> struct NodeContent : public E
        {
            NodeContent(const E &e) : E(e)
            {
            }
        };

        /* 封装元组类型推导逻辑 */
        template<class T>
        struct ElementTypeHelp
        {
            /* 推导非内置数组类型的元组类型 */
            typedef typename SelType<SIsInnerType<T>::value, SElement<T>,
                    typename SelType<SIsContainType<T>::value,
                    VContainElement<T>, MElement<T> >::type >::type result1;

            /* 推导内置数组类型的元组类型 */
            typedef typename SelType<SIsCharType<T>::value, ACElement, VElement<T, false> >::type result2;

            /* 推导内置数组类型的元组类型 */
            typedef typename SelType<SIsCharType<T>::value, ACElement, VElement<T, SIsInnerType<T>::value> >::type result3;

            /* 推导属性或者内容元组，这类元组的类型只可能是基础类型或者字符数组 */
            typedef typename SelType<SIsCharArrayType<T>::value, ACElement,
                    typename SelType<SIsInnerType<T>::value, SElement<T>, NullElement >::type >::type result4;

            /* 推导非字符数组的C数组元组类型 */
            typedef VOutElement<typename SArrayInnerType<T>::type, false> result5;
        };

        /* 属性元组构造函数 */
        template<class T>
        Attribute<typename ElementTypeHelp<T>::result4> ATTRIBUTE(const char * pcName, const T &stValue)
        {
            return Attribute<typename ElementTypeHelp<T>::result4>(ELEMENT(pcName, stValue));
        }

        /* 内容元组构造函数 */
        template<class T>
        NodeContent<typename ElementTypeHelp<T>::result4> CONTENT(const T &stValue)
        {
            return NodeContent<typename ElementTypeHelp<T>::result4>(ELEMENT("", stValue));
        }

        /* 非内置数组类型元组构造函数 */
        template<class T>
        typename ElementTypeHelp<T>::result1 ELEMENT(const char * pcName, const T &stValue)
        {
            typename ElementTypeHelp<T>::result1 stElem = {pcName, (T*)&stValue};
            return stElem;
        }

        /* 内置数组退化的指针类型元组构造函数 */
        template<class T>
        typename ElementTypeHelp<T>::result2 ELEMENT(const char * pcName, const T *pstValueList, LONG_32 lCount)
        {
            typename ElementTypeHelp<T>::result2 stElem = {pcName, pstValueList, lCount};
            return stElem;
        }

        /* 字符串指针类型元组构造函数 */
        //inline ACElement ELEMENT(const char * pcName, const char * pcStr)
        //{
        //    ACElement stElem = {pcName, pcStr, IMOS_strlen(pcStr)};
        //    return stElem;
        //}

        /* 内置数组类型元组构造函数 */
        template<class T, int N>
        typename ElementTypeHelp<T>::result3 ELEMENT(const char * pcName, const T (&astValueList)[N])
        {
            typename ElementTypeHelp<T>::result3 stElem = {pcName, astValueList, N};
            return stElem;
        }

        /* 非字符数组的C数组类型元组构造函数 */
        template<class T>
        typename ElementTypeHelp<T>::result5 ELEMENT(const char * pcName, T &stValueList, LONG_32 *plCount)
        {
            return ELEMENT(pcName, stValueList, plCount,
                (typename SelType<SIsArrayType<T>::value, TRUE_TYPE, FALSE_TYPE>::type *)0);
        }

        /* 非字符数组的C数组类型元组构造函数实现 */
        template<class T>
        VOutElement<T, false> ELEMENT(const char * pcName, const T *pstValueList, LONG_32 *plCount, FALSE_TYPE*)
        {
            VOutElement<T, false> stElem = {pcName, pstValueList, plCount};
            return stElem;
        }
        /* 非字符数组的C数组类型元组构造函数实现 */
        template<class T, int N>
        VOutElement<T, false> ELEMENT(const char * pcName, T (&astValueList)[N], LONG_32 *plCount, TRUE_TYPE*)
        {
            *plCount = N;
            VOutElement<T, false> stElem = {pcName, astValueList, plCount};
            return stElem;
        }

        template<class T>
        VMElement<T> ELEMENT(const char * pcName, LONG_32 idx, const T &stValue)
        {
            VMElement<T> stElem = {pcName, &stValue, idx};
            return stElem;
        }
    }
}

/* xml构造接口 */
namespace IMOS_SDK_XML {

    namespace UTILITY
    {
        /* 一组重载的将不同类型元组转换为xml片段的函数 */
        inline std::ostringstream & operator << (std::ostringstream &ostrXml, const NullElement &)
        {
            return ostrXml;
        }

        template<class T>
        std::ostringstream & operator << (std::ostringstream &ostrXml, const VContainElement<T> &oElem)
        {
            toxml(ostrXml, oElem, (typename SelType<VContainElement<T>::isInnerType, TRUE_TYPE, FALSE_TYPE>::type*)0);
            return ostrXml;
        }

        template<class T>
        VOID toxml (std::ostringstream &ostrXml, const VContainElement<T> &oElem, TRUE_TYPE*)
        {
            ostrXml << "<" << oElem.pcEleName << " count="IMOS_SDK_XML_QUOT << oElem.poContain->size() << IMOS_SDK_XML_QUOT">"
                    << "<![CDATA[";
            typename T::const_iterator it = oElem.poContain->begin();

            for (; it != oElem.poContain->end(); ++it)
            {
                ostrXml << *it << "\t";
            }
            ostrXml << "]]></" << oElem.pcEleName << ">";
        }
        template<class T>
        VOID toxml (std::ostringstream &ostrXml, const VContainElement<T> &oElem, FALSE_TYPE*)
        {
            typename T::const_iterator it = oElem.poContain->begin();
            for (; it != oElem.poContain->end(); ++it)
            {
                ostrXml << ELEMENT(oElem.pcEleName, SGetPointToData::value(*it));
            }
        }

        template<class T>
        std::ostringstream & operator << (std::ostringstream &ostrXml, const VElement<T, true> &oElem)
        {
            ostrXml << "<" << oElem.pcEleName << " count="IMOS_SDK_XML_QUOT << oElem.lCount << IMOS_SDK_XML_QUOT">";
            for (LONG_32 i=0; i<oElem.lCount; ++i)
            {
                ostrXml << oElem.pstValue[i] << " ";
            }
            ostrXml << "</" << oElem.pcEleName << ">";
            return ostrXml;
        }

        template<class T>
        std::ostringstream & operator << (std::ostringstream &ostrXml, const VElement<T, false> &oElem)
        {
            for (LONG_32 i=0; i<oElem.lCount; ++i)
            {
                ostrXml << ELEMENT(oElem.pcEleName, SGetPointToData::value(oElem.pstValue[i]));
            }

            return ostrXml;
        }

        template<class T>
        std::ostringstream & operator << (std::ostringstream &ostrXml, const MElement<T> oElem)
        {
            ostrXml <<  "<" << oElem.pcEleName << ">";
            xmlTempl(ostrXml, *oElem.pstValue);
            ostrXml << "</" << oElem.pcEleName << ">";
            return ostrXml;
        }

        template<class T>
        std::ostringstream & operator << (std::ostringstream &ostrXml, const SElement<T> &oElem)
        {
            ostrXml <<  "<" << oElem.pcEleName << ">" << *oElem.pValue << "</" << oElem.pcEleName << ">";
            return ostrXml;
        }

        inline std::ostringstream & operator << (std::ostringstream &ostrXml, const ACElement &oElem)
        {
            if (oElem.pcValue[0] == '\0')
            {
                ostrXml <<  "<" << oElem.pcEleName << "/>";
            }
            else
            {
                ostrXml <<  "<" << oElem.pcEleName << ">";

                for (LONG_32 i=0; i<oElem.lLen; ++i)
                {
                    switch(oElem.pcValue[i])
                    {
                    case '&':
                        ostrXml << "&amp;";
                        break;
                    case '>':
                        ostrXml << "&gt;";
                        break;
                    case '<':
                        ostrXml << "&lt;";
                        break;
                    case '\'':
                        ostrXml << "&apos;";
                        break;
                    case '\"':
                        ostrXml << "&quot;";
                        break;
                    case '\0':
                        i = oElem.lLen-1;
                        break;
                    default:
                        ostrXml << oElem.pcValue[i];
                    };
                }

                ostrXml << "</" << oElem.pcEleName << ">";
            }
            return ostrXml;
        }

        inline std::ostringstream & operator << (std::ostringstream &ostrXml, const SElement<std::string> &oElem)
        {
            ACElement oACElem = {oElem.pcEleName, oElem.pValue->c_str(), oElem.pValue->size()};
            return (ostrXml << oACElem);
        }

        /* 将一到多个元组构造为完整xml的函数 */
        template<class T1, class T2=NullElement, class T3=NullElement, class T4=NullElement, class T5=NullElement, class T6=NullElement>
        struct MultiElemXmlBuild
        {
            static std::string build(const char *pcRootTagName="",
                const T1 &stElement1=T1(),
                const T2 &stElement2=T2(),
                const T3 &stElement3=T3(),
                const T4 &stElement4=T4(),
                const T5 &stElement5=T5(),
                const T6 &stElement6=T6())
            {
                std::ostringstream ostrXml;
                ostrXml << "<?xml version="IMOS_SDK_XML_QUOT"1.0"IMOS_SDK_XML_QUOT"?>"
                    << "<" << pcRootTagName << ">";

                ostrXml << stElement1
                    << stElement2
                    << stElement3
                    << stElement4
                    << stElement5
                    << stElement6
                    << "</" << pcRootTagName << ">";

                return ostrXml.str();
            }
        };
    }

    using namespace UTILITY;

    /* 把结构的数据转换为xml */
    template<class T>
    std::string buildXml(const T &stData, const char *pcTagName = NULL)
    {
        if (NULL == pcTagName)
        {
            pcTagName = "data";
        }
        return buildSingleEleXml(ELEMENT(pcTagName, stData));
    }

    /* 单个元组的数据转换为xml */
    template<class T>
    std::string buildSingleEleXml(const T &stElem)
    {
        std::ostringstream ostrXml;
        ostrXml << "<?xml version="IMOS_SDK_XML_QUOT"1.0"IMOS_SDK_XML_QUOT"?>";
        ostrXml << stElem;

        return ostrXml.str();
    }

    /* 以下一组函数将一到多个元组的数据转换为xml */
    template<class T1>
    std::string buildMultiEleXml(const char *pcRootTagName,
        const T1 &stElement1)
    {
        return MultiElemXmlBuild<T1>::build(pcRootTagName, stElement1);
    }

    template<class T1, class T2>
    std::string buildMultiEleXml(const char *pcRootTagName,
        const T1 &stElement1,
        const T2 &stElement2)
    {
        return MultiElemXmlBuild<T1, T2>::build(pcRootTagName, stElement1, stElement2);
    }

    template<class T1, class T2, class T3>
    std::string buildMultiEleXml(const char *pcRootTagName,
        const T1 &stElement1,
        const T2 &stElement2,
        const T3 &stElement3)
    {
        return MultiElemXmlBuild<T1, T2, T3>::build(pcRootTagName, stElement1, stElement2, stElement3);
    }

    template<class T1, class T2, class T3, class T4>
    std::string buildMultiEleXml(const char *pcRootTagName,
        const T1 &stElement1,
        const T2 &stElement2,
        const T3 &stElement3,
        const T4 &stElement4)
    {
        return MultiElemXmlBuild<T1, T2, T3, T4>::build(pcRootTagName, stElement1, stElement2, stElement3, stElement4);
    }

    template<class T1, class T2, class T3, class T4, class T5>
    std::string buildMultiEleXml(const char *pcRootTagName,
        const T1 &stElement1,
        const T2 &stElement2,
        const T3 &stElement3,
        const T4 &stElement4,
        const T5 &stElement5)
    {
        return MultiElemXmlBuild<T1, T2, T3, T4, T5>::build(pcRootTagName, stElement1, stElement2, stElement3, stElement4, stElement5);
    }

    template<class T1, class T2, class T3, class T4, class T5, class T6>
    std::string buildMultiEleXml(const char *pcRootTagName,
        const T1 &stElement1,
        const T2 &stElement2,
        const T3 &stElement3,
        const T4 &stElement4,
        const T5 &stElement5,
        const T6 &stElement6)
    {
        return MultiElemXmlBuild<T1, T2, T3, T4, T5, T6>::build(pcRootTagName, stElement1, stElement2, stElement3, stElement4, stElement5, stElement6);
    }
}

/* xml解析接口 */
namespace IMOS_SDK_XML {

    namespace UTILITY
    {
        /* libxml2库函数的动态加载类 */
        struct libxml : DLL<libxml>
        {
            ADD_FUN(xmlParseFile, XMLPUBFUN xmlDocPtr (XMLCALL*)(const char *filename))
            ADD_FUN(xmlParseMemory, XMLPUBFUN xmlDocPtr (XMLCALL *)(const char *, int))
            ADD_FUN(xmlReadMemory, XMLPUBFUN xmlDocPtr (XMLCALL *)(const char *, int , const char *, const char *, int))
            ADD_FUN(xmlFreeDoc, XMLPUBFUN void (XMLCALL *)(xmlDocPtr))
            ADD_FUN(xmlDocGetRootElement, XMLPUBFUN xmlNodePtr (XMLCALL *)(xmlDocPtr))
            ADD_FUN(xmlNodeGetContent, XMLPUBFUN xmlChar * (XMLCALL *)(xmlNodePtr))
            ADD_FUN(xmlMemGet, XMLPUBFUN int (XMLCALL *)(xmlFreeFunc *, xmlMallocFunc *, xmlReallocFunc *, xmlStrdupFunc *))
            ADD_FUN(xmlGetProp, XMLPUBFUN xmlChar * (XMLCALL*)(xmlNodePtr, const xmlChar *))
            ADD_FUN(xmlHasProp, XMLPUBFUN xmlAttrPtr (XMLCALL*)(xmlNodePtr, const xmlChar *))
            ADD_FUN_UNLOAD(xmlFree, xmlFreeFunc)
        };

        /* 封装一组xml解析操作 */
        class CXmlParseHelp
        {
        public:

            /* 构造函数 */
            CXmlParseHelp()
            {
                m_pDoc = NULL;
            }

            /* 析构函数 */
            ~CXmlParseHelp()
            {
                if (NULL != m_pDoc)
                {
                    try
                    {
                        libxml::methods.xmlFreeDoc(m_pDoc);
                        m_pDoc = NULL;
                    }
                    catch (...)
                    {
                    }
                }
            }

            /* 加载libxml2库 */
            static bool loadXmlLib(const std::string & strDllPath)
            {
                if (!libxml::loadDll(strDllPath.c_str()))
                {
                    return false;
                }

                libxml::methods.xmlMemGet(&libxml::methods.xmlFree, NULL, NULL, NULL);
                if (NULL == libxml::methods.xmlFree)
                {
                    libxml::unloadDll();
                    return false;
                }

                return true;
            }

            /* 卸载libxml2库 */
            static void freeXmlLib()
            {
                libxml::unloadDll();
                return;
            }

            /* 读xml文件 */
            xmlNodePtr readXmlFile(const char *pcFilePath)
            {
                if ((NULL == libxml::methods.xmlParseFile) || (NULL == libxml::methods.xmlDocGetRootElement))
                {
                    return NULL;
                }

                /* 读入文件内容 */
                m_pDoc = libxml::methods.xmlParseFile(pcFilePath);

                xmlNodePtr pRootNode = NULL;

                /* 获取根节点 */
                if ((NULL == m_pDoc) ||
                    (NULL == (pRootNode = libxml::methods.xmlDocGetRootElement(m_pDoc))))
                {
                    return NULL;
                }

                return pRootNode;
            }

            /* 读xml字符串 */
            xmlNodePtr readXmlString(const char *pcXml, ULONG_32 ulLen)
            {
                if ((NULL == libxml::methods.xmlParseMemory) || (NULL == libxml::methods.xmlDocGetRootElement))
                {
                    return NULL;
                }

                /* 读入xml字符串 */
                m_pDoc = libxml::methods.xmlParseMemory(pcXml, (int)ulLen);

                xmlNodePtr pRootNode = NULL;

                /* 获取根节点 */
                if ((NULL == m_pDoc) ||
                    (NULL == (pRootNode = libxml::methods.xmlDocGetRootElement(m_pDoc))))
                {
                    return NULL;
                }

                return pRootNode;
            }

            /* 查找指定名称的子节点 */
            static xmlNodePtr searchXmlSubNode(IN xmlNodePtr pParentNode, IN const std::string &strSubNodeName)
            {
                if (NULL == pParentNode)
                {
                    return NULL;
                }

                /* 遍历每个子节点 */
                xmlNodePtr pCurNode = pParentNode->xmlChildrenNode;
                while (NULL != pCurNode)
                {
                    /* 找到名字相同的节点，则返回 */
                    if ((const char*)pCurNode->name == strSubNodeName)
                    {
                        return pCurNode;
                    }

                    pCurNode = pCurNode->next;
                }
                return NULL;
            }

            /* 读取指定名称的字符串属性值 */
            static bool getXmlNodeAttribute(IN xmlNodePtr pNode, IN const std::string &strName, OUT const std::string &strContent)
            {
                if ((NULL == pNode) || (NULL == libxml::methods.xmlGetProp) || (NULL == libxml::methods.xmlFree))
                {
                    return false;
                }
                /* 获取节点的值 */
                CHAR *pcKey = (CHAR *) libxml::methods.xmlGetProp(pNode, (const xmlChar*)strName.c_str());
                if (NULL == pcKey)
                {
                    return false;
                }

                (std::string&)strContent = pcKey;

                /* 释放内存 */
                libxml::methods.xmlFree((xmlChar *) pcKey);

                return true;
            }

            /* 读取指定名称的字符属性值 */
            static bool getXmlNodeAttribute(IN xmlNodePtr pNode, IN const std::string &strName, OUT const char &lValue)
            {
                std::string strContent;
                if (!getXmlNodeAttribute(pNode, strName, strContent))
                {
                    return false;
                }
                (char &)lValue = strContent.at(0);
                return true;
            }

            /* 读取指定名称的整形属性值 */
            template <class T>
            static bool getXmlNodeAttribute(IN xmlNodePtr pNode, IN const std::string &strName, OUT const T &lValue)
            {
                std::string strContent;
                if (!getXmlNodeAttribute(pNode, strName, strContent))
                {
                    return false;
                }

                if (sizeof(T) == sizeof(DLONG))
                {
                    (T&)lValue = (T)IMOS_atodul(strContent.c_str());
                }
                else
                {
                    (T&)lValue = (T)IMOS_atol(strContent.c_str());
                }

                return true;
            }

            /* 读取xml节点的文本内容 */
            static bool getXmlNodeContent(IN xmlNodePtr pNode, OUT const std::string &strContent)
            {
                if ((NULL == pNode) || (NULL == libxml::methods.xmlNodeGetContent) || (NULL == libxml::methods.xmlFree))
                {
                    return false;
                }

                /* 获取节点的值 */
                CHAR *pcKey = (CHAR *) libxml::methods.xmlNodeGetContent(pNode);
                if (NULL == pcKey)
                {
                    return false;
                }

                (std::string&)strContent = pcKey;

                /* 释放内存 */
                libxml::methods.xmlFree((xmlChar *) pcKey);

                return true;
            }

            /* 读取xml节点CHAR类型文本内容 */
            static bool getXmlNodeContent(IN xmlNodePtr pNode, OUT const char &lValue)
            {
                std::string strContent;
                if (!getXmlNodeContent(pNode, strContent))
                {
                    return false;
                }
                (char &)lValue = strContent.at(0);
                return true;
            }

            /* 读取xml节点整形文本内容 */
            template <class T>
            static bool getXmlNodeContent(IN xmlNodePtr pNode, OUT const T &lValue)
            {
                std::string strContent;
                if (!getXmlNodeContent(pNode, strContent))
                {
                    return false;
                }

                if (sizeof(T) == sizeof(DLONG))
                {
                    (T&)lValue = (T)IMOS_atodul(strContent.c_str());
                }
                else
                {
                    (T&)lValue = (T)IMOS_atol(strContent.c_str());
                }
                return true;
            }

            /* 获取当前节点下指定名称的所有子节点 */
            static void getXmlSubNodes(IN xmlNodePtr pNode, IN const CHAR *pcSubNodeName, OUT std::vector<xmlNodePtr> &oSubNodes)
            {
                if ((NULL == pNode) || (NULL == pcSubNodeName))
                {
                    return;
                }
                pNode = pNode->xmlChildrenNode;
                while (NULL != pNode)
                {
                    if ((const char*)pNode->name == std::string(pcSubNodeName))
                    {
                        oSubNodes.push_back(pNode);
                    }
                    pNode = pNode->next;
                }
                return;
            }

        private:

            xmlDocPtr m_pDoc;
        };


        /* 包含多个元组的xml解析函数 */
        template<class T1, class T2=NullElement, class T3=NullElement, class T4=NullElement, class T5=NullElement, class T6=NullElement>
        struct MultiElemXmlParse
        {
            /* 解析内存xml字符串 */
            static bool parse(const char *pcXml="",
                const T1 &stElement1=T1(),
                const T2 &stElement2=T2(),
                const T3 &stElement3=T3(),
                const T4 &stElement4=T4(),
                const T5 &stElement5=T5(),
                const T6 &stElement6=T6())
            {
                CXmlParseHelp oParser;
                xmlNodePtr pRootNode = oParser.readXmlString(pcXml, (ULONG_32) strlen(pcXml));

                return (NULL != pRootNode) &&
                    (pRootNode << stElement1) &&
                    (pRootNode << stElement2) &&
                    (pRootNode << stElement3) &&
                    (pRootNode << stElement4) &&
                    (pRootNode << stElement5) &&
                    (pRootNode << stElement6);
            }

            /* 解析xml文件 */
            static bool parseFile(const char *pcFilePath,
                const T1 &stElement1=T1(),
                const T2 &stElement2=T2(),
                const T3 &stElement3=T3(),
                const T4 &stElement4=T4(),
                const T5 &stElement5=T5(),
                const T6 &stElement6=T6())
            {
                CXmlParseHelp oParser;
                xmlNodePtr pRootNode = oParser.readXmlFile(pcFilePath);

                return (NULL != pRootNode) &&
                    (pRootNode << stElement1) &&
                    (pRootNode << stElement2) &&
                    (pRootNode << stElement3) &&
                    (pRootNode << stElement4) &&
                    (pRootNode << stElement5) &&
                    (pRootNode << stElement6);
            }
        };

        /* 读取空元组 */
        inline bool operator << (xmlNodePtr /*pParentNode*/, const NullElement &/*oElem*/)
        {
            return true;
        }

        /* 读取非数组类型元素元组 */
        template<class T>
        bool operator << (xmlNodePtr pParentNode, const T &oElem)
        {
            xmlNodePtr pNode = CXmlParseHelp::searchXmlSubNode(pParentNode, oElem.pcEleName);
            if (NULL == pNode)
            {
                return false;
            }

            return readElem(pNode, oElem);
        }

        /* 读取非字符数组类型属性元组 */
        template<class E>
        bool operator << (xmlNodePtr pParentNode, const Attribute<E> &oElem)
        {
            return CXmlParseHelp::getXmlNodeAttribute(pParentNode, oElem.pcEleName, *oElem.pValue);
        }

        /* 读取字符数组类型属性元组 */
        inline bool operator << (xmlNodePtr pParentNode, const Attribute<ACElement> &oElem)
        {
            std::string strValue;
            if (!CXmlParseHelp::getXmlNodeAttribute(pParentNode, oElem.pcEleName, strValue))
            {
                return false;
            }

            strncpy((char*)oElem.pcValue, strValue.c_str(), (unsigned int)oElem.lLen);
            return true;
        }

        /* 读取非字符数组类型内容元组 */
        template<class E>
        bool operator << (xmlNodePtr pParentNode, const NodeContent<E> &oElem)
        {
            return CXmlParseHelp::getXmlNodeContent(pParentNode, *oElem.pValue);
        }
        /* 读取字符数组类型内容元组 */
        inline bool operator << (xmlNodePtr pParentNode, const NodeContent<ACElement> &oElem)
        {
            std::string strValue;
            if (!CXmlParseHelp::getXmlNodeContent(pParentNode, strValue))
            {
                return false;
            }

            strncpy((char*)oElem.pcValue, strValue.c_str(), (unsigned int)oElem.lLen);
            return true;
        }

        /* 读取非字符数组类型元素元组，不需要指定数组长度 */
        template<class T, bool bInner>
        bool operator << (xmlNodePtr pParentNode, const VElement<T, bInner> &oElem)
        {
            VOutElement<T, bInner> oOutElem = {oElem.pcEleName, oElem.pstValue, (LONG_32*)&oElem.lCount};
            return readElem(pParentNode, oOutElem);
        }

        /* 读取非字符数组类型元素元组，需要指定数组长度 */
        template<class T, bool bInner>
        bool operator << (xmlNodePtr pParentNode, const VOutElement<T, bInner> &oElem)
        {
            return readElem(pParentNode, oElem);
        }

        /* 读取stl容器类型元素元组 */
        template<class TContain>
        bool operator << (xmlNodePtr pParentNode, const VContainElement<TContain> &oElem)
        {
            return readElem(pParentNode, oElem);
        }

        /* 读取基础类型元素元组 */
        template<class T>
        bool readElem(xmlNodePtr pNode, const SElement<T> &oElem)
        {
            return CXmlParseHelp::getXmlNodeContent(pNode, *oElem.pValue);
        }

        /* 读取字符数组类型元素元组 */
        inline bool readElem(xmlNodePtr pNode, const ACElement &oElem)
        {
            std::string strContent;
            if (!CXmlParseHelp::getXmlNodeContent(pNode, strContent))
            {
                return false;
            }

            strncpy((char*)oElem.pcValue, strContent.c_str(), (unsigned int)oElem.lLen);

            return true;
        }

        /* 读取基础类型数组的元素元组 */
        template<class T>
        bool readElem(xmlNodePtr pNode, const VOutElement<T, true> &oElem)
        {
            std::string strContent;
            if (!CXmlParseHelp::getXmlNodeContent(pNode, strContent))
            {
                return false;
            }

            std::istringstream istr(strContent);
            LONG_32 lValue = 0;
            int i=0;
            for (; (!(istr >> lValue).eof()) && (i < *oElem.plCount); ++i)
            {
                (T&)oElem.pstValue[i] = (T)lValue;
            }
            *oElem.plCount = i;
            return true;
        }

        /* 读取结构类型数组的元素元组 */
        template<class T>
        bool readElem(xmlNodePtr pNode, const VOutElement<T, false> &oElem)
        {
            std::vector<xmlNodePtr> oSubNodes;
            CXmlParseHelp::getXmlSubNodes(pNode, oElem.pcEleName, oSubNodes);
            size_t i=0;
            for (; (i<oSubNodes.size()) && (i<(size_t)*oElem.plCount); ++i)
            {
                if (!readElem(oSubNodes[i], ELEMENT(oElem.pcEleName, oElem.pstValue[i])))
                {
                    return false;
                }
            }
            *oElem.plCount = i;
            return true;
        }

        /* 读取结构类型数组的元素元组 */
        template<class T>
        bool readElem(xmlNodePtr pNode, const VMElement<T> &oElem)
        {
            std::vector<xmlNodePtr> oSubNodes;
            CXmlParseHelp::getXmlSubNodes(pNode, oElem.pcEleName, oSubNodes);
            if (oSubNodes.size() <= (size_t)oElem.index)
            {
                return false;
            }
            return xmlTempl(oSubNodes[oElem.index], (T&)(*oElem.pstValue));
        }

        /* 读取结构类型的元素元组 */
        template<class T>
        bool readElem(xmlNodePtr pNode, const MElement<T> &oElem)
        {
            return xmlTempl(pNode, (T&)*oElem.pstValue);
        }

        /* 读取stl容器类型元素元组 */
        template<class TContain>
        bool readElem(xmlNodePtr pNode, const VContainElement<TContain> &oElem)
        {
            std::vector<xmlNodePtr> oSubNodes;
            CXmlParseHelp::getXmlSubNodes(pNode, oElem.pcEleName, oSubNodes);
            for (size_t i=0; i<oSubNodes.size(); ++i)
            {
                typename TContain::value_type value;
                if (!readElem(oSubNodes[i], ELEMENT(oElem.pcEleName, value)))
                {
                    return false;
                }
                oElem.poContain->insert(oElem.poContain->end(),value);
            }
            return true;
        }
    }

    using namespace UTILITY;

    /* 解析xml字符串到结构 */
    template<class T>
    bool parseXml(const CHAR *pcXml, const CHAR *pcTagName, T &oData)
    {
        return parseSingleEleXml(pcXml, ELEMENT(pcTagName, oData));
    }

    /* 解析xml文件到结构 */
    template<class T>
    bool parseXmlFile(const CHAR *pcFile, const CHAR *pcTagName, T &oData)
    {
        return parseSingleEleXmlFile(pcFile, ELEMENT(pcTagName, oData));
    }

    /* 解析xml字符串到单个的元组 */
    template<class T>
    bool parseSingleEleXml(const CHAR *pcXml, const T &stElem)
    {
        /* 调用xml解析模块接口获取xml文档结构及文档根元素 */
        CXmlParseHelp oParser;
        xmlNodePtr pRootNode = oParser.readXmlString(pcXml, (ULONG_32) strlen(pcXml));
        if ((stElem.pcEleName != NULL) && (stElem.pcEleName[0] != '\0'))
        {
            return (NULL != pRootNode) && (pRootNode << stElem);
        }
        else
        {
            return (NULL != pRootNode) && readElem(pRootNode, stElem);
        }
    }

    /* 解析xml字符串到一到多个元组 */
    template<class T>
    bool parseMultiEleXml(const char *pcXml,
        const T &stElement)
    {
        return MultiElemXmlParse<T>::parse(pcXml, stElement);
    }

    template<class T1, class T2>
    bool parseMultiEleXml(const char *pcXml,
        const T1 &stElement1,
        const T2 &stElement2)
    {
        return MultiElemXmlParse<T1, T2>::parse(pcXml, stElement1, stElement2);
    }

    template<class T1, class T2, class T3>
    bool parseMultiEleXml(const char *pcXml,
        const T1 &stElement1,
        const T2 &stElement2,
        const T3 &stElement3)
    {
        return MultiElemXmlParse<T1, T2, T3>::parse(pcXml, stElement1, stElement2, stElement3);
    }

    template<class T1, class T2, class T3, class T4>
    bool parseMultiEleXml(const char *pcXml,
        const T1 &stElement1,
        const T2 &stElement2,
        const T3 &stElement3,
        const T4 &stElement4)
    {
        return MultiElemXmlParse<T1, T2, T3, T4>::parse(pcXml, stElement1, stElement2, stElement3, stElement4);
    }

    template<class T1, class T2, class T3, class T4, class T5>
    bool parseMultiEleXml(const char *pcXml,
        const T1 &stElement1,
        const T2 &stElement2,
        const T3 &stElement3,
        const T4 &stElement4,
        const T5 &stElement5)
    {
        return MultiElemXmlParse<T1, T2, T3, T4, T5>::parse(pcXml, stElement1, stElement2, stElement3, stElement4, stElement5);
    }

    template<class T1, class T2, class T3, class T4, class T5, class T6>
    bool parseMultiEleXml(const char *pcXml,
        const T1 &stElement1,
        const T2 &stElement2,
        const T3 &stElement3,
        const T4 &stElement4,
        const T5 &stElement5,
        const T6 &stElement6)
    {
        return MultiElemXmlParse<T1, T2, T3, T4, T5, T6>::parse(pcXml, stElement1, stElement2, stElement3, stElement4, stElement5, stElement6);
    }

    /* 解析xml文件到单个的元组 */
    template<class T>
    bool parseSingleEleXmlFile(const CHAR *pcFilePath, const T &stElem)
    {
        /* 调用xml解析模块接口获取xml文档结构及文档根元素 */
        CXmlParseHelp oParser;
        xmlNodePtr pRootNode = oParser.readXmlFile(pcFilePath);
        if ((stElem.pcEleName != NULL) && (stElem.pcEleName[0] != '\0'))
        {
            return (NULL != pRootNode) && (pRootNode << stElem);
        }
        else
        {
            return (NULL != pRootNode) && readElem(pRootNode, stElem);
        }
    }

    /* 解析xml文件到一到多个元组 */
    template<class T>
    bool parseMultiEleXmlFile(const char *pcPath,
        const T &stElement)
    {
        return MultiElemXmlParse<T>::parseFile(pcPath, stElement);
    }
    template<class T1, class T2>
    bool parseMultiEleXmlFile(const char *pcPath,
        const T1 &stElement1,
        const T2 &stElement2)
    {
        return MultiElemXmlParse<T1, T2>::parseFile(pcPath, stElement1, stElement2);
    }

    template<class T1, class T2, class T3>
    bool parseMultiEleXmlFile(const char *pcPath,
        const T1 &stElement1,
        const T2 &stElement2,
        const T3 &stElement3)
    {
        return MultiElemXmlParse<T1, T2, T3>::parseFile(pcPath, stElement1, stElement2, stElement3);
    }

    template<class T1, class T2, class T3, class T4>
    bool parseMultiEleXmlFile(const char *pcPath,
        const T1 &stElement1,
        const T2 &stElement2,
        const T3 &stElement3,
        const T4 &stElement4)
    {
        return MultiElemXmlParse<T1, T2, T3, T4>::parseFile(pcPath, stElement1, stElement2, stElement3, stElement4);
    }

    template<class T1, class T2, class T3, class T4, class T5>
    bool parseMultiEleXmlFile(const char *pcPath,
        const T1 &stElement1,
        const T2 &stElement2,
        const T3 &stElement3,
        const T4 &stElement4,
        const T5 &stElement5)
    {
        return MultiElemXmlParse<T1, T2, T3, T4, T5>::parseFile(pcPath, stElement1, stElement2, stElement3, stElement4, stElement5);
    }

    template<class T1, class T2, class T3, class T4, class T5, class T6>
    bool parseMultiEleXmlFile(const char *pcPath,
        const T1 &stElement1,
        const T2 &stElement2,
        const T3 &stElement3,
        const T4 &stElement4,
        const T5 &stElement5,
        const T6 &stElement6)
    {
        return MultiElemXmlParse<T1, T2, T3, T4, T5, T6>::parseFile(pcPath, stElement1, stElement2, stElement3, stElement4, stElement5, stElement6);
    }
}
/*lint -restore */

#endif //IMOS_SDK_XML_H
