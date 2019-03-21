package tunnel.bayonet;

import org.springframework.stereotype.Component;
import tunnel.exception.CustomException;
import tunnel.sdk.struct.imos.*;

/**
 * @描述: 卡口统一对外提供的接口
 *        如果有其他各个厂家，需要实现该接口
 * @作者: REN
 * @时间: 2019/2/27 11:21
 */
public interface BayonetHandler {

    void init() throws CustomException;

    /**
     *
     * 功能描述:
     *      实时车辆信息
     * @auther: 任琳珺
     * @date: 2019-02-27
     * @param:
     * @return:
     */
    void actualInfo() throws CustomException;

    /**
     *
     * 功能描述:
     *          查询卡口下的摄像机列表
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    TagTollgateVideoCameraQueryItem[] listVideoCameraByBayonet(String tollgageCode) throws CustomException;


    /**
     *
     * 功能描述:
     *          查询卡口下的照相机列表
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    TagTollgateCameraInfo[] listCameraByBayonet(String tollgageCode) throws CustomException;


    /**
     *
     * 功能描述:
     *  开启实况直播，以流的形式获取
     * @auther:
     * @date:
     * @param:
     * @return:
     */
    void startLiveVideoStream() throws CustomException;

    /**
     *
     * 功能描述:
     *  停止实况直播
     * @auther: 任琳珺
     * @date: 2019-03-18
     * @param:
     * @return:
     */
    void stopLiveVideoStream() throws CustomException;

    /**
     *
     * 功能描述: 查询组织下的卡口列表
     *
     * @auther: 任琳珺
     * @date: 2019-03-18
     * @param:
     *          szOrgCode 组织编码
     * @return:
     */
    TagTollgateInfo[] IMOS_QueryTollgateList(String szOrgCode) throws CustomException;


}

