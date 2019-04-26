package tunnel.core;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/4/23 16:01
 */
public class ImageData {

    /** 图像索引 */
    private int imageIndex;
    /** 图像名称完整路径 */
    private String imageURL;
    /** 图像类型 */
    private int imageType;
    /** 编码格式 */
    private int imageFormat;
    /** 封装格式 */
    private int encapFormat;
    /** 图像宽度 */
    private int imageWidth;
    /** 图像高度 */
    private int imageHeight;
    /** 经过时刻 */
    private String passTime;

    public int getImageIndex() {
        return imageIndex;
    }

    public void setImageIndex(int imageIndex) {
        this.imageIndex = imageIndex;
    }

    public String getImageURL() {
        return imageURL;
    }

    public void setImageURL(String imageURL) {
        this.imageURL = imageURL;
    }

    public int getImageType() {
        return imageType;
    }

    public void setImageType(int imageType) {
        this.imageType = imageType;
    }

    public int getImageFormat() {
        return imageFormat;
    }

    public void setImageFormat(int imageFormat) {
        this.imageFormat = imageFormat;
    }

    public int getEncapFormat() {
        return encapFormat;
    }

    public void setEncapFormat(int encapFormat) {
        this.encapFormat = encapFormat;
    }

    public int getImageWidth() {
        return imageWidth;
    }

    public void setImageWidth(int imageWidth) {
        this.imageWidth = imageWidth;
    }

    public int getImageHeight() {
        return imageHeight;
    }

    public void setImageHeight(int imageHeight) {
        this.imageHeight = imageHeight;
    }

    public String getPassTime() {
        return passTime;
    }

    public void setPassTime(String passTime) {
        this.passTime = passTime;
    }
}
