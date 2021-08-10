package Logined;

import java.util.Scanner;
import Preparing.Quit;
import Preparing.Welcome;
import Tools.AccountMessage;
import Tools.CleanConsole;
import Tools.GroupsFileOperation;
import Tools.Guide;

/**
 * @ClassName Function.java
 * @Package Logined
 * @author XHW
 * @date 2019年12月9日
 * @Description 功能导航作用
 */
public class Function extends AccountMessage implements Guide {
	
	@Override
	/**
	 * @MethodName guide
	 * @see Tools.Guide#guide()
	 * @param 
	 * @return 
	 * @throws 
	 * @Description TODO
	 */
	public void guide() {
		
		// TODO Auto-generated method stub
		System.out.println("*****************");
		System.out.println("请选择你需要的功能！");
		System.out.println("1.联系人操作");
		System.out.println("2.分组操作");
		System.out.println("3.查询操作");
		System.out.println("4.黑名单操作");
		System.out.println("5.账户设置");
		System.out.println("6.返回登录界面");
		System.out.println("7.退出");
		System.out.println("请您选择：");
	
		Scanner input = new Scanner(System.in);                 // System.in 只能关闭一次
		String choose = input.next();
		
		if(choose.equals("1")) {
			CleanConsole.clear();
			ContactOperation contactOperation = new ContactOperation();
			contactOperation.setAccountFileMessage(this.getAccountFileMessage());
			contactOperation.guide();	
		}
		else if(choose.equals("2")){
			CleanConsole.clear();
			GroupOperation groupOperation = new GroupOperation();
			groupOperation.setAccountFileMessage(this.getAccountFileMessage());
			groupOperation.guide();
		}
		else if(choose.equals("3")) {
			CleanConsole.clear();
			QueryOperation operation = new QueryOperation();
			operation.setAccountFileMessage(this.getAccountFileMessage());
			operation.guide();
		}
		else if(choose.equals("4")){
			CleanConsole.clear();
			BlacklistOperation blacklistOperation = new BlacklistOperation();
			blacklistOperation.setAccountFileMessage(this.getAccountFileMessage());
			blacklistOperation.guide();
		}
		else if(choose.equals("5")){
			CleanConsole.clear();
			AccountSet accountSet = new AccountSet();
			accountSet.verify();
			accountSet.guide();
		}
		else if(choose.equals("6")) {
			CleanConsole.clear();
			Welcome.welcome();
		}
		else if(choose.equals("7")) {
			CleanConsole.clear();
			Quit.quit();
		}
		else {
			System.out.println("请按照提示正确的输入！");
			CleanConsole.clear();
			guide();
		}
	}
	
}
