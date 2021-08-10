package Logined;

import java.util.Scanner;

import Preparing.Welcome;
import Tools.AccountOperation;
import Tools.CleanConsole;
import Tools.FileOperation;
import Tools.Guide;
/**
 * @ClassName AccountSet.java
 * @Package Logined
 * @author XHW
 * @date 2019年12月9日
 * @Description 实现账户设置的功能
 */
public class AccountSet extends AccountOperation implements Guide{
	
	/**
	 * @MethodName verify
	 * @Description 账户进行设置前先需要验证信息
	 */
	public void verify() {
		System.out.println("*****************");
		System.out.println("需要先确认您的信息！");
		accountVerify();
		
		System.out.println("请输出您的密码：");
		Scanner input = new Scanner(System.in); 
		String pass = input.next();
		setPassword(pass);
		setAccountFilename();
		
		int flag = FileOperation.checkDoubleFilename(getAccountFilename());
		if(flag == 1) {
			System.out.println("确认成功！");
		}
		else {
			System.out.println("信息有误！请检查！");
			CleanConsole.clear();
			verify();
		}
	}
	
	@Override
	public void guide()
	{
		CleanConsole.clear();
		System.out.println("*****************");
		System.out.println("请选择你需要的功能！");
		System.out.println("1.修改手机号绑定");
		System.out.println("2.修改密码");
		System.out.println("3.返回操作界面");
		System.out.println("4.注销账户");
		System.out.println("请您选择：");
		
		Scanner input = new Scanner(System.in);                 // System.in 只能关闭一次
		String choose = input.next();
		
		if(choose.equals("1")) {
			CleanConsole.clear();
			changeAccount();
		}
		else if(choose.equals("2")) {
			CleanConsole.clear();
			changePassword();
		}
		else if(choose.equals("3")) {
			CleanConsole.clear();
			new Function().guide();
		}
		else {
			CleanConsole.clear();
			deleteAccount();
		}
	}
	
	/**
	 * @MethodName changeAccount
	 * @Description 修改手机绑定操作
	 */
	public void changeAccount()
	{
		int flag = FileOperation.modifyAccount(getAccountFilename(), getPassword());
		if(flag == 1)
		{
			System.out.println("修改成功！");
			CleanConsole.clear();
			new Function().guide();
		}
	}
	
	public void changePassword()
	{
		int flag = FileOperation.findFilePassword(getAccount());
		if(flag == 1)
		{
			System.out.println("修改成功！");
			CleanConsole.clear();
			new Function().guide();
		}
	}
	
	/**
	 * @MethodName deleteAccount
	 * @Description 实现注销账户操作
	 */
	public void deleteAccount() {
		Scanner input = new Scanner(System.in); 
		
		System.out.println("*****************");
		System.out.println("确认要注销账户？");
		System.out.println("1.我在想想");
		System.out.println("2.残忍注销");
		
		int choose = input.nextInt();
		if(choose == 1) {
			guide();
		}
		if(choose == 2) {
			FileOperation.deleteAcoount(getAccountFilename());
			System.out.println("注销成功！");
			CleanConsole.clear();
			Welcome.welcome();
		}
		
	}
	
}
