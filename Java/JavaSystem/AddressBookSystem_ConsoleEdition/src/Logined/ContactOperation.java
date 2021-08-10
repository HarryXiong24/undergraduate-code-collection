package Logined;

import java.util.ArrayList;
import java.util.Scanner;
import Tools.AccountMessage;
import Tools.CleanConsole;
import Tools.Contact;
import Tools.FileOperation;
import Tools.GroupsFileOperation;
import Tools.Guide;

/**
 * @ClassName ContactOperation.java
 * @Package Logined
 * @author XHW
 * @date 2019年12月9日
 * @Description 实现联系人操作功能
 */
public class ContactOperation extends AccountMessage implements Guide{
	
	@Override
	public void guide() {
		System.out.println("*****************");
		System.out.println("请选择你需要的功能！");
		System.out.println("1.新建联系人");
		System.out.println("2.修改联系人");
		System.out.println("3.删除联系人");
		System.out.println("4.返回功能界面");
		System.out.println("请您选择：");
		
		Scanner input = new Scanner(System.in);                 // System.in 只能关闭一次
		String choose = input.next();
		
		if(choose.equals("1")) {
			CleanConsole.clear();
			createContact();
		}
		else if(choose.equals("2")) {
			CleanConsole.clear();
			modifyContact();
		}
		else if(choose.equals("3")) {
			CleanConsole.clear();
			deleteContact();
		}
		else if(choose.equals("4")){
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
	
	/**
	 * @MethodName createContact
	 * @Description 创建新联系人
	 */
	public void createContact() {
		Scanner input = new Scanner(System.in);
		
		System.out.println("请输入联系人姓名：");
		String name = input.next();
		System.out.println("请输入联系人性别：");
		String sex = input.next();
		
		System.out.println("请输入联系人电话的个数：");
		int n = input.nextInt();
		ArrayList<String> phonenumbers = new ArrayList<String>();
		for(int i = 0; i < n; i++) {
			System.out.printf("请输入电话%d：\n", i+1);
			phonenumbers.add(input.next());
		}
		
		System.out.println("请输入联系人邮箱：");
		String email = input.next();
		System.out.println("请输入联系人分组：");
		String group = input.next();
		
		//对分组是否存在的检查，有则加入，无则创建
		int flag1 = GroupsFileOperation.checkGroupExist(group, getAccountFileMessage());
		if(flag1 == 0) {
			System.out.println("改分组之前不存在，已为您创建！");
			GroupsFileOperation.addGroupFile(group, getAccountFileMessage());
		}
		System.out.println("请输入联系人备注：");
		String other = input.next();
		
		Contact contact = new Contact(name, sex, phonenumbers, email, group, other);
		int flag = FileOperation.InputFile(contact, getAccountFileMessage());
		
		if(flag == 1) {
			System.out.println("创建成功！");
			CleanConsole.clear();
			guide();
		}
	}
	
	/**
	 * @MethodName modifyContact
	 * @Description 修改联系人信息
	 */
	public void modifyContact() {
		Scanner input = new Scanner(System.in);
		
		System.out.println("请输入修改联系人的信息！");
		System.out.println("请输入联系人姓名：");
		String name = input.next();
		System.out.println("请输入联系人性别：");
		String sex = input.next();
		
		System.out.println("请输入联系人电话的个数：");
		int n = input.nextInt();
		ArrayList<String> phonenumbers = new ArrayList<String>();
		for(int i = 0; i < n; i++) {
			System.out.printf("请输入电话%d：\n", i+1);
			phonenumbers.add(input.next());
		}
		
		System.out.println("请输入联系人邮箱：");
		String email = input.next();
		
		System.out.println("请输入联系人分组：");
		String group = input.next();
		
		//对分组是否存在的检查，有则加入，无则创建
		int flag1 = GroupsFileOperation.checkGroupExist(group, getAccountFileMessage());
		if(flag1 == 0) {
			System.out.println("改分组之前不存在，已为您创建！");
			GroupsFileOperation.addGroupFile(group, getAccountFileMessage());
		}
		
		System.out.println("请输入联系人备注：");
		String other = input.next();
		
		Contact contact = new Contact(name, sex, phonenumbers, email, group, other);
		
		int flag2 = FileOperation.modifyContact(getAccountFileMessage(), contact, name);
		if(flag2 == 1) {
			System.out.println("修改成功！");
			CleanConsole.clear();
			guide();
		}
		else {
			System.out.println("没有该联系人！");
			CleanConsole.clear();
			guide();
		}
		
	}
	
	/**
	 * @MethodName deleteContact
	 * @Description 删除联系人
	 */
	public void deleteContact() {
		Scanner input = new Scanner(System.in);
		String name = null;
		
		System.out.println("请输入你要删除的联系人：");
		name = input.next();
		
		int flag = FileOperation.deleteContact(getAccountFileMessage(), name);
		
		if(flag == 1) {
			System.out.println("删除成功！");
			CleanConsole.clear();
			guide();
		}
		else {
			System.out.println("没有该联系人！");
			CleanConsole.clear();
			guide();
		}
	}

}
