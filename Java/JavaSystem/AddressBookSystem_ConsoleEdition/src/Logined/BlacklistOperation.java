package Logined;

import java.util.Scanner;
import Tools.AccountMessage;
import Tools.BlacklistFileOperation;
import Tools.CleanConsole;
import Tools.FileOperation;
import Tools.Guide;

public class BlacklistOperation extends AccountMessage implements Guide {

	@Override
	public void guide() {
		// TODO Auto-generated method stub
		System.out.println("*****************");
		System.out.println("请选择你需要的功能！");
		System.out.println("1.加入黑名单");
		System.out.println("2.移出黑名单");
		System.out.println("3.显示黑名单");
		System.out.println("4.返回功能界面");
		System.out.println("请您选择：");
		
		Scanner input = new Scanner(System.in);                 // System.in 只能关闭一次
		String choose = input.next();
		
		if(choose.equals("1")) {
			CleanConsole.clear();
			addToBlacklist();
		}
		else if(choose.equals("2")) {
			CleanConsole.clear();
			removeFromBlacklist();
		}
		else if(choose.equals("3")) {
			CleanConsole.clear();
			showBlacklist();
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

	public void addToBlacklist() {
		// TODO Auto-generated method stub
		System.out.println("请输入要加入黑名单联系人的姓名：");
		Scanner input = new Scanner(System.in);
		String name = input.next();
		
		int flag = BlacklistFileOperation.addToBlacklistFile(getAccountFileMessage(), name);
		if(flag == 0) {
			System.out.println("不存在该联系人！");
			CleanConsole.clear();
			guide();
		}
		else {
			System.out.println("添加成功，并已在联系人列表删除该联系人！");
			CleanConsole.clear();
			guide();
		}
	}
	
	public void removeFromBlacklist() {
		// TODO Auto-generated method stub
		System.out.println("请输入要移出黑名单联系人的姓名：");
		Scanner input = new Scanner(System.in);
		String name = input.next();
		
		int flag = BlacklistFileOperation.removeFromBlacklistFile(getAccountFileMessage(), name);
		if(flag == 0) {
			System.out.println("不存在该联系人！");
			CleanConsole.clear();
			guide();
		}
		else {
			System.out.println("移出成功，并加入联系人列表！");
			CleanConsole.clear();
			guide();
		}
	}

	public void showBlacklist() {
		// TODO Auto-generated method stub
		System.out.println("以下是黑名单里所有联系人信息！");
		BlacklistFileOperation.showBlacklist(getAccountFileMessage());
		
		System.out.println("请按0返回！");
		Scanner input = new Scanner(System.in);
		String choose = input.next();
		
		if(choose.equals("0")){
			CleanConsole.clear();
			guide();
		}
	}
	
}
