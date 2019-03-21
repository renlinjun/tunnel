package tunnel.exception;


/**
 * @描述:
 * @作者: REN
 * @时间: 2018/11/28 19:11
 */
public class CustomException extends Exception {
    private int code;
    private String msg;
    private Class<?> clazz;

    public CustomException(int code, String message) {
        this(code, message, null);
    }

    public CustomException(int code, String msg, Class<?> clazz) {
        super();
        this.code = code;
        this.msg = msg;
        this.clazz = clazz;
    }

    public int getCode() {
        return this.code;
    }
    public String getMsg() {
        return this.msg;
    }
}
