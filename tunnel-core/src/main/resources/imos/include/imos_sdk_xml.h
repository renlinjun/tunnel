/*******************************************************************************
Copyright (c) 2008-2013, Zhejiang Uniview Technology Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                                    imos_sdk_xml.h
Project Code: imos sdk
Module Name: imos sdk
Date Created: 2011-10-24
Author: chengjian/03354
Description: xml���������ܴ��룬�̳���IMOS_ActiveX�ؼ����̣��Ǳ��α�д����

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

/* ��׼������ǰ������ */
namespace std{
    template<class _Ty, class _Ax> class vector;
    template<class _Ty, class _Ax> class list;
    template<class _Ty, class _Ax> class deque;
    template<class _Kty,class _Pr, class _Alloc> class set;
    template<class _Kty,class _Pr, class _Alloc> class multiset;
}

/* ���������� */
namespace IMOS_SDK_XML
{
    namespace UTILITY
    {
        /* true���� */
        struct TRUE_TYPE{};
        /* false���� */
        struct FALSE_TYPE{};

        /* ����ѡ��Ԫ���� */
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

        /* �ж�T�Ƿ�Ϊchar���͵�Ԫ���� */
        template<class T> struct SIsCharType
        {
            static long test(...);
            static char test(const CHAR *);
            static char test(const UCHAR *);
            enum {value = (sizeof(test((T *)0)) == sizeof(char))};
        };

        /* �ж�T�Ƿ�Ϊ�������͵�Ԫ���� */
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

        /* �ж�T�Ƿ�Ϊstl�������͵�Ԫ���� */
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

        /* �ж�T�Ƿ�Ϊ�����������͵�Ԫ���� */
        template<class T> struct SIsArrayType
        {
            static long test(...);
            template<class K, int N> static char test(const K (*)[N]);
            enum {value = (sizeof(test((T *)0)) == sizeof(char))};
        };

        /* �ж�T�Ƿ�Ϊchar�������͵�Ԫ���� */
        template<class T> struct SIsCharArrayType
        {
            static long test(...);
            template<int N> static char test(const CHAR (*)[N]);
            template<int N> static char test(const UCHAR (*)[N]);
            enum {value = (sizeof(test((T *)0)) == sizeof(char))};
        };

        /* ��ȡ����T����Ԫ�����͵�Ԫ���� */
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

        /* ��ȡָ��ָ�����ݵ�Ԫ���������Դ���༶ָ�� */
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

            /* �ж��Ƿ�Ϊ��ָ�� */
            template<class T>
            static bool is_null(T &v)
            {
                return STypeWrapper<T>::is_null(v);
            }

            /* ȡ��ָ��ָ�����ݵ����� */
            template<class T>
            static typename STypeWrapper<T>::type &value(T &v)
            {
                return STypeWrapper<T>::value(v);
            }
        };

        /* ��Ԫ�� */
        struct NullElement
        {
        };

        /* �ַ������ַ�����Ԫ�� */
        struct ACElement
        {
            const char *pcEleName;
            const char *pcValue;
            LONG_32 lLen;
        };

        /* ��������Ԫ�� */
        template<class T> struct SElement
        {
            const char *pcEleName;
            const T *pValue;
        };

        /* �ṹ����Ԫ�� */
        template<class T> struct MElement
        {
            const char *pcEleName;
            const T* pstValue;
        };

        /* stl��������Ԫ�� */
        template<class T> struct VContainElement
        {
            enum {isInnerType = SIsInnerType<typename T::value_type>::value};
            const char *pcEleName;
            T *poContain;
        };

        /* ��������Ԫ�飬TΪ����Ԫ�����ͣ�bIsInType��ʾT�Ƿ�Ϊ�������� */
        template<class T, bool bIsInType> struct VElement
        {
            const char *pcEleName;
            const T* pstValue;
            LONG_32 lCount;
        };

        /* ��������Ԫ�飬TΪ����Ԫ�����ͣ�bIsInType��ʾT�Ƿ�Ϊ�������� */
        template<class T, bool bIsInType> struct VOutElement
        {
            const char *pcEleName;
            const T* pstValue;
            LONG_32 *plCount;
        };

        /* ��������Ԫ�� */
        template<class T> struct VMElement
        {
            const char *pcEleName;
            const T* pstValue;
            int index;
        };

        /* ����Ԫ�飬�̳���Ԫ��Ԫ���ʵ�� */
        template<class E> struct Attribute : public E
        {
            Attribute(const E &e) : E(e)
            {
            }
        };

        /* �ڵ�����Ԫ�飬�̳���Ԫ��Ԫ���ʵ�� */
        template<class E> struct NodeContent : public E
        {
            NodeContent(const E &e) : E(e)
            {
            }
        };

        /* ��װԪ�������Ƶ��߼� */
        template<class T>
        struct ElementTypeHelp
        {
            /* �Ƶ��������������͵�Ԫ������ */
            typedef typename SelType<SIsInnerType<T>::value, SElement<T>,
                    typename SelType<SIsContainType<T>::value,
                    VContainElement<T>, MElement<T> >::type >::type result1;

            /* �Ƶ������������͵�Ԫ������ */
            typedef typename SelType<SIsCharType<T>::value, ACElement, VElement<T, false> >::type result2;

            /* �Ƶ������������͵�Ԫ������ */
            typedef typename SelType<SIsCharType<T>::value, ACElement, VElement<T, SIsInnerType<T>::value> >::type result3;

            /* �Ƶ����Ի�������Ԫ�飬����Ԫ�������ֻ�����ǻ������ͻ����ַ����� */
            typedef typename SelType<SIsCharArrayType<T>::value, ACElement,
                    typename SelType<SIsInnerType<T>::value, SElement<T>, NullElement >::type >::type result4;

            /* �Ƶ����ַ������C����Ԫ������ */
            typedef VOutElement<typename SArrayInnerType<T>::type, false> result5;
        };

        /* ����Ԫ�鹹�캯�� */
        template<class T>
        Attribute<typename ElementTypeHelp<T>::result4> ATTRIBUTE(const char * pcName, const T &stValue)
        {
            return Attribute<typename ElementTypeHelp<T>::result4>(ELEMENT(pcName, stValue));
        }

        /* ����Ԫ�鹹�캯�� */
        template<class T>
        NodeContent<typename ElementTypeHelp<T>::result4> CONTENT(const T &stValue)
        {
            return NodeContent<typename ElementTypeHelp<T>::result4>(ELEMENT("", stValue));
        }

        /* ��������������Ԫ�鹹�캯�� */
        template<class T>
        typename ElementTypeHelp<T>::result1 ELEMENT(const char * pcName, const T &stValue)
        {
            typename ElementTypeHelp<T>::result1 stElem = {pcName, (T*)&stValue};
            return stElem;
        }

        /* ���������˻���ָ������Ԫ�鹹�캯�� */
        template<class T>
        typename ElementTypeHelp<T>::result2 ELEMENT(const char * pcName, const T *pstValueList, LONG_32 lCount)
        {
            typename ElementTypeHelp<T>::result2 stElem = {pcName, pstValueList, lCount};
            return stElem;
        }

        /* �ַ���ָ������Ԫ�鹹�캯�� */
        //inline ACElement ELEMENT(const char * pcName, const char * pcStr)
        //{
        //    ACElement stElem = {pcName, pcStr, IMOS_strlen(pcStr)};
        //    return stElem;
        //}

        /* ������������Ԫ�鹹�캯�� */
        template<class T, int N>
        typename ElementTypeHelp<T>::result3 ELEMENT(const char * pcName, const T (&astValueList)[N])
        {
            typename ElementTypeHelp<T>::result3 stElem = {pcName, astValueList, N};
            return stElem;
        }

        /* ���ַ������C��������Ԫ�鹹�캯�� */
        template<class T>
        typename ElementTypeHelp<T>::result5 ELEMENT(const char * pcName, T &stValueList, LONG_32 *plCount)
        {
            return ELEMENT(pcName, stValueList, plCount,
                (typename SelType<SIsArrayType<T>::value, TRUE_TYPE, FALSE_TYPE>::type *)0);
        }

        /* ���ַ������C��������Ԫ�鹹�캯��ʵ�� */
        template<class T>
        VOutElement<T, false> ELEMENT(const char * pcName, const T *pstValueList, LONG_32 *plCount, FALSE_TYPE*)
        {
            VOutElement<T, false> stElem = {pcName, pstValueList, plCount};
            return stElem;
        }
        /* ���ַ������C��������Ԫ�鹹�캯��ʵ�� */
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

/* xml����ӿ� */
namespace IMOS_SDK_XML {

    namespace UTILITY
    {
        /* һ�����صĽ���ͬ����Ԫ��ת��ΪxmlƬ�εĺ��� */
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

        /* ��һ�����Ԫ�鹹��Ϊ����xml�ĺ��� */
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

    /* �ѽṹ������ת��Ϊxml */
    template<class T>
    std::string buildXml(const T &stData, const char *pcTagName = NULL)
    {
        if (NULL == pcTagName)
        {
            pcTagName = "data";
        }
        return buildSingleEleXml(ELEMENT(pcTagName, stData));
    }

    /* ����Ԫ�������ת��Ϊxml */
    template<class T>
    std::string buildSingleEleXml(const T &stElem)
    {
        std::ostringstream ostrXml;
        ostrXml << "<?xml version="IMOS_SDK_XML_QUOT"1.0"IMOS_SDK_XML_QUOT"?>";
        ostrXml << stElem;

        return ostrXml.str();
    }

    /* ����һ�麯����һ�����Ԫ�������ת��Ϊxml */
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

/* xml�����ӿ� */
namespace IMOS_SDK_XML {

    namespace UTILITY
    {
        /* libxml2�⺯���Ķ�̬������ */
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

        /* ��װһ��xml�������� */
        class CXmlParseHelp
        {
        public:

            /* ���캯�� */
            CXmlParseHelp()
            {
                m_pDoc = NULL;
            }

            /* �������� */
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

            /* ����libxml2�� */
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

            /* ж��libxml2�� */
            static void freeXmlLib()
            {
                libxml::unloadDll();
                return;
            }

            /* ��xml�ļ� */
            xmlNodePtr readXmlFile(const char *pcFilePath)
            {
                if ((NULL == libxml::methods.xmlParseFile) || (NULL == libxml::methods.xmlDocGetRootElement))
                {
                    return NULL;
                }

                /* �����ļ����� */
                m_pDoc = libxml::methods.xmlParseFile(pcFilePath);

                xmlNodePtr pRootNode = NULL;

                /* ��ȡ���ڵ� */
                if ((NULL == m_pDoc) ||
                    (NULL == (pRootNode = libxml::methods.xmlDocGetRootElement(m_pDoc))))
                {
                    return NULL;
                }

                return pRootNode;
            }

            /* ��xml�ַ��� */
            xmlNodePtr readXmlString(const char *pcXml, ULONG_32 ulLen)
            {
                if ((NULL == libxml::methods.xmlParseMemory) || (NULL == libxml::methods.xmlDocGetRootElement))
                {
                    return NULL;
                }

                /* ����xml�ַ��� */
                m_pDoc = libxml::methods.xmlParseMemory(pcXml, (int)ulLen);

                xmlNodePtr pRootNode = NULL;

                /* ��ȡ���ڵ� */
                if ((NULL == m_pDoc) ||
                    (NULL == (pRootNode = libxml::methods.xmlDocGetRootElement(m_pDoc))))
                {
                    return NULL;
                }

                return pRootNode;
            }

            /* ����ָ�����Ƶ��ӽڵ� */
            static xmlNodePtr searchXmlSubNode(IN xmlNodePtr pParentNode, IN const std::string &strSubNodeName)
            {
                if (NULL == pParentNode)
                {
                    return NULL;
                }

                /* ����ÿ���ӽڵ� */
                xmlNodePtr pCurNode = pParentNode->xmlChildrenNode;
                while (NULL != pCurNode)
                {
                    /* �ҵ�������ͬ�Ľڵ㣬�򷵻� */
                    if ((const char*)pCurNode->name == strSubNodeName)
                    {
                        return pCurNode;
                    }

                    pCurNode = pCurNode->next;
                }
                return NULL;
            }

            /* ��ȡָ�����Ƶ��ַ�������ֵ */
            static bool getXmlNodeAttribute(IN xmlNodePtr pNode, IN const std::string &strName, OUT const std::string &strContent)
            {
                if ((NULL == pNode) || (NULL == libxml::methods.xmlGetProp) || (NULL == libxml::methods.xmlFree))
                {
                    return false;
                }
                /* ��ȡ�ڵ��ֵ */
                CHAR *pcKey = (CHAR *) libxml::methods.xmlGetProp(pNode, (const xmlChar*)strName.c_str());
                if (NULL == pcKey)
                {
                    return false;
                }

                (std::string&)strContent = pcKey;

                /* �ͷ��ڴ� */
                libxml::methods.xmlFree((xmlChar *) pcKey);

                return true;
            }

            /* ��ȡָ�����Ƶ��ַ�����ֵ */
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

            /* ��ȡָ�����Ƶ���������ֵ */
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

            /* ��ȡxml�ڵ���ı����� */
            static bool getXmlNodeContent(IN xmlNodePtr pNode, OUT const std::string &strContent)
            {
                if ((NULL == pNode) || (NULL == libxml::methods.xmlNodeGetContent) || (NULL == libxml::methods.xmlFree))
                {
                    return false;
                }

                /* ��ȡ�ڵ��ֵ */
                CHAR *pcKey = (CHAR *) libxml::methods.xmlNodeGetContent(pNode);
                if (NULL == pcKey)
                {
                    return false;
                }

                (std::string&)strContent = pcKey;

                /* �ͷ��ڴ� */
                libxml::methods.xmlFree((xmlChar *) pcKey);

                return true;
            }

            /* ��ȡxml�ڵ�CHAR�����ı����� */
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

            /* ��ȡxml�ڵ������ı����� */
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

            /* ��ȡ��ǰ�ڵ���ָ�����Ƶ������ӽڵ� */
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


        /* �������Ԫ���xml�������� */
        template<class T1, class T2=NullElement, class T3=NullElement, class T4=NullElement, class T5=NullElement, class T6=NullElement>
        struct MultiElemXmlParse
        {
            /* �����ڴ�xml�ַ��� */
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

            /* ����xml�ļ� */
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

        /* ��ȡ��Ԫ�� */
        inline bool operator << (xmlNodePtr /*pParentNode*/, const NullElement &/*oElem*/)
        {
            return true;
        }

        /* ��ȡ����������Ԫ��Ԫ�� */
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

        /* ��ȡ���ַ�������������Ԫ�� */
        template<class E>
        bool operator << (xmlNodePtr pParentNode, const Attribute<E> &oElem)
        {
            return CXmlParseHelp::getXmlNodeAttribute(pParentNode, oElem.pcEleName, *oElem.pValue);
        }

        /* ��ȡ�ַ�������������Ԫ�� */
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

        /* ��ȡ���ַ�������������Ԫ�� */
        template<class E>
        bool operator << (xmlNodePtr pParentNode, const NodeContent<E> &oElem)
        {
            return CXmlParseHelp::getXmlNodeContent(pParentNode, *oElem.pValue);
        }
        /* ��ȡ�ַ�������������Ԫ�� */
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

        /* ��ȡ���ַ���������Ԫ��Ԫ�飬����Ҫָ�����鳤�� */
        template<class T, bool bInner>
        bool operator << (xmlNodePtr pParentNode, const VElement<T, bInner> &oElem)
        {
            VOutElement<T, bInner> oOutElem = {oElem.pcEleName, oElem.pstValue, (LONG_32*)&oElem.lCount};
            return readElem(pParentNode, oOutElem);
        }

        /* ��ȡ���ַ���������Ԫ��Ԫ�飬��Ҫָ�����鳤�� */
        template<class T, bool bInner>
        bool operator << (xmlNodePtr pParentNode, const VOutElement<T, bInner> &oElem)
        {
            return readElem(pParentNode, oElem);
        }

        /* ��ȡstl��������Ԫ��Ԫ�� */
        template<class TContain>
        bool operator << (xmlNodePtr pParentNode, const VContainElement<TContain> &oElem)
        {
            return readElem(pParentNode, oElem);
        }

        /* ��ȡ��������Ԫ��Ԫ�� */
        template<class T>
        bool readElem(xmlNodePtr pNode, const SElement<T> &oElem)
        {
            return CXmlParseHelp::getXmlNodeContent(pNode, *oElem.pValue);
        }

        /* ��ȡ�ַ���������Ԫ��Ԫ�� */
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

        /* ��ȡ�������������Ԫ��Ԫ�� */
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

        /* ��ȡ�ṹ���������Ԫ��Ԫ�� */
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

        /* ��ȡ�ṹ���������Ԫ��Ԫ�� */
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

        /* ��ȡ�ṹ���͵�Ԫ��Ԫ�� */
        template<class T>
        bool readElem(xmlNodePtr pNode, const MElement<T> &oElem)
        {
            return xmlTempl(pNode, (T&)*oElem.pstValue);
        }

        /* ��ȡstl��������Ԫ��Ԫ�� */
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

    /* ����xml�ַ������ṹ */
    template<class T>
    bool parseXml(const CHAR *pcXml, const CHAR *pcTagName, T &oData)
    {
        return parseSingleEleXml(pcXml, ELEMENT(pcTagName, oData));
    }

    /* ����xml�ļ����ṹ */
    template<class T>
    bool parseXmlFile(const CHAR *pcFile, const CHAR *pcTagName, T &oData)
    {
        return parseSingleEleXmlFile(pcFile, ELEMENT(pcTagName, oData));
    }

    /* ����xml�ַ�����������Ԫ�� */
    template<class T>
    bool parseSingleEleXml(const CHAR *pcXml, const T &stElem)
    {
        /* ����xml����ģ��ӿڻ�ȡxml�ĵ��ṹ���ĵ���Ԫ�� */
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

    /* ����xml�ַ�����һ�����Ԫ�� */
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

    /* ����xml�ļ���������Ԫ�� */
    template<class T>
    bool parseSingleEleXmlFile(const CHAR *pcFilePath, const T &stElem)
    {
        /* ����xml����ģ��ӿڻ�ȡxml�ĵ��ṹ���ĵ���Ԫ�� */
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

    /* ����xml�ļ���һ�����Ԫ�� */
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
