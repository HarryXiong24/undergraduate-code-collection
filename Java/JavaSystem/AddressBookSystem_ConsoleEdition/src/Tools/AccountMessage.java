package Tools;

/**
 * @ClassName AccountMessage.java
 * @Package Tools
 * @author XHW
 * @date 2019年12月9日
 * @Description 抽象类，用于需要账户信息的类的继承
 */
public abstract class AccountMessage {
	private String accountFileMessage = null;                           // 获取登录名和密码，便于之后操作
	
	public String getAccountFileMessage() {
		return accountFileMessage;
	}

	public void setAccountFileMessage(String accountFileMessage) {
		this.accountFileMessage = accountFileMessage;
	}

}
