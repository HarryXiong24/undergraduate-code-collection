package Tools;

import java.util.Scanner;

import Logined.Function;

/**
 * @ClassName AccountOperation.java
 * @Package Tools
 * @author XHW
 * @date 2019年12月9日
 * @Description 抽象类，包含账户操作的基本功能
 */
public abstract class AccountOperation {
	private String account;
  	private String password;
  	private String accountFilename;
  	
	public String getAccount() {
		return account;
	}

	public void setAccount(String account) {
		this.account = account;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public String getAccountFilename() {
		return accountFilename;
	}

	public void setAccountFilename() {
		this.accountFilename = account + password + ".txt";
	}
	
	public void regist() {
		
	}
	
	public void login() {
		
	}
	
	public void finding() {
	
	}
	
	/**
	 * @MethodName accountVerify
	 * @Description 输入账户验证
	 */
	public void accountVerify() {
		Scanner input = new Scanner(System.in);
		boolean match = false;
		
		do {
			System.out.println("请输入您的账户名(账户名即为用户手机号，11位数):");
			account  = input.next();
			String accountErgex = "[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]";
			match = account.matches(accountErgex);
			if(match) {
				break;
			}
			else {
				CleanConsole.clear();
				System.out.println("账号必须为11位数且只能为数字，请重新输入！");
			}
		}while(!match);
	}
	
	/**
	 * @MethodName passwordVerify
	 * @Description 输入密码验证
	 * @return int
	 */
	public int passwordVerify() {
		Scanner input = new Scanner(System.in);
		
		int flag = 3;
		do {
			System.out.println("请输入您的密码：");
			password  = input.next();
			
			setAccountFilename();
			int back = FileOperation.accountFileOutput(getAccountFilename());
			
			if(back == 1) {
				System.out.println("登录成功！");
				break;
			}
			else {
				flag = flag - 1;
				System.out.printf("您还有%d次机会！\n", flag);
			}
		}while(flag != 0);
		
		return flag;
	}
	
	/**
	 * @MethodName doublepasswordVerify
	 * @Description 设置密码验证
	 */
	public void doublepasswordVerify() {
		Scanner input = new Scanner(System.in);
		boolean match = false;
		
		do {
			int flag = 0;
			System.out.println("请输入您的密码：");
			password  = input.next();
			String passwordErgex = "^(?![0-9]+$)(?![a-zA-Z]+$)[0-9A-Za-z]{6,16}$";             // 含字母和数字
			match = password.matches(passwordErgex );
			if(match) {
				flag = 1;
			}
			else {
				CleanConsole.clear();
				System.out.println("密码必须含字母和数字，且必须在6-16位数！");
				match = false;
			}
			
			if(flag == 1){
				System.out.println("请确认您的密码：");
				String verifypassword  = input.next();
				if(verifypassword.equals(password)) {
					break;
				}
				else{
					CleanConsole.clear();
					match = false;
					System.out.println("两次输入不一致！");
				}
			}
		}while(!match);
		
		setAccount(account);
		setPassword(password);
		setAccountFilename();
	}
  
}
