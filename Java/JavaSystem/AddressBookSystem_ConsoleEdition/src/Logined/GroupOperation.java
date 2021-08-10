package Logined;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;
import Tools.AccountMessage;
import Tools.CleanConsole;
import Tools.Contact;
import Tools.FileOperation;
import Tools.GroupsFileOperation;
import Tools.Guide;

/**
 * @ClassName GroupOperation.java
 * @Package Logined
 * @author XHW
 * @date 2019年12月9日
 * @Description 实现分组操作的功能
 */
public class GroupOperation extends AccountMessage implements Guide {
	
	private ArrayList<String> groups = new ArrayList<String>();
	
	@Override
	public void guide() {
		// TODO Auto-generated method stub
		System.out.println("*****************");
		System.out.println("请选择你需要的功能！");
		System.out.println("1.新建分组");
		System.out.println("2.修改分组");
		System.out.println("3.删除分组");
		System.out.println("4.返回功能界面");
		System.out.println("请您选择：");
		
		Scanner input = new Scanner(System.in);                 // System.in 只能关闭一次
		String choose = input.next();
		
		if(choose.equals("1")) {
			CleanConsole.clear();
			createGroups();
		}
		else if(choose.equals("2")) {
			CleanConsole.clear();
			modifyGroups();
		}
		else if(choose.equals("3")) {
			CleanConsole.clear();
			deleteGroups();
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

	public void createGroups() {
		Scanner input = new Scanner(System.in);
		
		System.out.println("请输入要创建分组的个数");
		int num = input.nextInt();
		
		System.out.println("请输入每个分组的名字");
		for(int i = 0; i < num; i++) {
			groups.add(input.next());
		}
		
		int flag = GroupsFileOperation.createGroupFile(groups, getAccountFileMessage());
		if(flag == 1) {
			System.out.println("创建成功！");
			CleanConsole.clear();
			guide();
		}

	}
	
	public void modifyGroups() {
		Scanner input = new Scanner(System.in);
		
		System.out.println("请输入修改联系人的信息！");
		System.out.println("请输入分组名字：");
		String group = input.next();
		
		//对分组是否存在的检查，有则加入，无则创建
		int flag1 = GroupsFileOperation.checkGroupExist(group, getAccountFileMessage());
		if(flag1 == 0) {
			System.out.println("改分组之前不存在，已为您创建！");
			GroupsFileOperation.addGroupFile(group, getAccountFileMessage());
			CleanConsole.clear();
			guide();
		}
		else {
			System.out.println("请输入改变后的分组名字：");
			String newGroupName = input.next();
			int flag2 = GroupsFileOperation.modifyGroup(group, getAccountFileMessage(), newGroupName);
			if(flag2 == 1) {
				System.out.println("修改成功！");
				CleanConsole.clear();
				guide();
			}
		}	
	
	}
	
	public void deleteGroups() {
		Scanner input = new Scanner(System.in);
		String name = null;
		
		System.out.println("请输入你要删除的分组名：");
		name = input.next();
		
		int flag = GroupsFileOperation.deleteContact(name, getAccountFileMessage());
		
		if(flag == 1) {
			System.out.println("删除成功！");
			CleanConsole.clear();
			guide();
		}
		else {
			System.out.println("没有该分组！");
			CleanConsole.clear();
			guide();
		}
		
	}	
}
