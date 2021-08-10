package Preparing;

import java.util.Scanner;

import Tools.AccountOperation;
import Tools.CleanConsole;
import Tools.FileOperation;

/**
 * @ClassName Finding.java
 * @Package Preparing
 * @author XHW
 * @time 下午9:36:33
 * @Description 找回密码的功能
 */
class Finding extends AccountOperation {
	
	@Override
	/**
	 * @MethodName finding
	 * @Override @see Tools.AccountOperation#finding()
	 * @param 
	 * @return 
	 * @throws 
	 * @Description 实现找回密码的功能
	 */
	public void finding() {
		System.out.println("请输入您的账户名：");
		Scanner input = new Scanner(System.in);
		String accountInput = input.next();
		setAccount(accountInput);
		
		int back = FileOperation.findFilePassword(getAccount());
		if(back == 0)
		{
			System.out.println("账户名错误！");
			CleanConsole.clear();
			Welcome.welcome();
		}
		else {
			System.out.println("找回成功！");
			CleanConsole.clear();
			Welcome.welcome();
		}
	}
	
}
