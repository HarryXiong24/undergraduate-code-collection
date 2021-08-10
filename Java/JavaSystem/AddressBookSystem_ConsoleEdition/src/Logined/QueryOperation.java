package Logined;

import java.util.Scanner;
import Tools.AccountMessage;
import Tools.CleanConsole;
import Tools.FileOperation;
import Tools.GroupsFileOperation;
import Tools.Guide;

/**
 * @ClassName QueryOperation.java
 * @Package Logined
 * @author XHW
 * @date 2019年12月9日
 * @Description 实现查询功能
 */
public class QueryOperation extends AccountMessage implements Guide {

	@Override
	public void guide() {
		// TODO Auto-generated method stub
		System.out.println("*****************");
		System.out.println("请选择你需要的查询方式！");
		System.out.println("1.显示所有联系人");
		System.out.println("2.指定查询联系人");
		System.out.println("3.按分组显示所有联系人");
		System.out.println("4.查询指定分组");
		System.out.println("5.返回功能界面");
		System.out.println("请您选择：");
		
		Scanner input = new Scanner(System.in);                 // System.in 只能关闭一次
		String choose = input.next();
		
		if(choose.equals("1")) {
			CleanConsole.clear();
			showContact();
		}
		else if(choose.equals("2")) {
			CleanConsole.clear();
			queryContact();
		}
		else if(choose.equals("3")) {
			CleanConsole.clear();
			showGroups();
		}
		else if(choose.equals("4")) {
			CleanConsole.clear();
			queryGroups();
		}
		else if(choose.equals("5")){
			CleanConsole.clear();
			Function function = new Function();
			function.setAccountFileMessage(this.getAccountFileMessage());
			function.guide();
		}
		else {
			System.out.println("请按照提示正确的输入！");
			CleanConsole.clear();
			guide();
		}
	}
	
	public void showContact() {
		// TODO Auto-generated method stub
		System.out.println("以下是所有联系人信息！");
		FileOperation.showContact(getAccountFileMessage());
		
		System.out.println("请按0返回！");
		Scanner input = new Scanner(System.in);
		String choose = input.next();
		
		if(choose.equals("0")){
			CleanConsole.clear();
			guide();
		}
	}
	
	public void queryContact() {
		// TODO Auto-generated method stub
		System.out.println("请输入要查询联系人的姓名：");
		Scanner input = new Scanner(System.in);
		String name = input.next();
		
		int flag = FileOperation.queryContact(getAccountFileMessage(), name);
		if(flag == 0) {
			System.out.println("不存在该联系人！");
			CleanConsole.clear();
			guide();
		}
		else {
			System.out.println("请按0返回！");
			String choose = input.next();
			
			if(choose.equals("0")){
				CleanConsole.clear();
				guide();
			}
		}
	}
	
	public void showGroups() {
		// TODO Auto-generated method stub
		System.out.println("以下是分组后所有联系人信息！");
		FileOperation.showGroups(getAccountFileMessage());
		
		System.out.println("请按0返回！");
		Scanner input = new Scanner(System.in);
		String choose = input.next();
		
		if(choose.equals("0")){
			CleanConsole.clear();
			guide();
		}
	}
	
	public void queryGroups() {
		// TODO Auto-generated method stub
		System.out.println("请输入要查询分组的组名：");
		Scanner input = new Scanner(System.in);
		String groupName = input.next();
		
		int flag = GroupsFileOperation.checkGroupExist(groupName, getAccountFileMessage());
		if(flag == 1) {
			FileOperation.queryGroups(getAccountFileMessage(), groupName);
			System.out.println("请按0返回！");
			String choose = input.next();
			
			if(choose.equals("0")){
				CleanConsole.clear();
				guide();
			}
		}
		else {
			System.out.println("不存在该分组！");
			CleanConsole.clear();
			guide();
		}
	}
	
}
