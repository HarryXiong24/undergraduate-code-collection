package Preparing;

import java.util.Scanner;
import Tools.CleanConsole;

/**
 * @ClassName Welcome.java
 * @Package Preparing
 * @author XHW
 * @time 下午9:21:47
 * @Description 欢迎的界面
 */

public class Welcome {

	/**
	 * @MethodName welcome
	 * @param 
	 * @return void
	 * @throws 
	 * @Description 选择相关的操作并执行
	 */
	public static void welcome() {
		// TODO Auto-generated method stub
		System.out.println("*****************");
		System.out.println("欢迎使用XHW通讯录系统！");
		System.out.println("1.注册");
		System.out.println("2.登录");
		System.out.println("3.找回密码");
		System.out.println("4.退出");
		System.out.println("请您选择：");
		
		Scanner input = new Scanner(System.in);                 // System.in 只能关闭一次
		String choose = input.next();
		
		if(choose.equals("1")) {
			CleanConsole.clear();
			new Regist().regist();
		}
		else if(choose.equals("2")) {
			CleanConsole.clear();
			new Login().login();
		}
		else if(choose.equals("3")) {
			CleanConsole.clear();
			new Finding().finding();
		}
		else if(choose.equals("4")) {
			CleanConsole.clear();
			Quit.quit();
		}
		else {
			System.out.println("请按照提示正确的输入！");
			CleanConsole.clear();
			Welcome.welcome();
		}	
	}
}
