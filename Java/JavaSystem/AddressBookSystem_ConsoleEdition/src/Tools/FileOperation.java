package Tools;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

/**
 * @ClassName FileOperation.java
 * @Package Tools
 * @author XHW
 * @time 上午9:35:57
 * @Description 提供文件操作功能
 */
public class FileOperation {
		
		/**
		 * @MethodName accountFileCreateOrOverride
		 * @return void
		 * @Description 创建文件账户或覆写文件信息
		 * @param filename
		 * @param account
		 * @param password
		 */
		public static void accountFileCreateOrOverride(String filename, String account, String password) {
			try {
				FileWriter newFile = new FileWriter(filename);
				BufferedWriter newFileBuffer = new BufferedWriter(newFile);
				newFileBuffer.write(account + password);
				newFileBuffer.newLine();
				newFileBuffer.newLine();
				newFileBuffer.close();
				newFile.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
				System.out.println("文件创建出错！");
			}
		}
		
		/**
		 * @MethodName accountFileOutput
		 * @Description 判断文件账户信息, 判断密码是否正确
		 * @param filename
		 * @return int
		 */
		public static int accountFileOutput(String filename) {
			try {
				FileReader fileReader = new FileReader(filename);
				fileReader.close();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				System.out.println("密码错误！");
				return 0;
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		
			return 1;
		}
		
		/**
		 * @MethodName checkDoubleFilename
		 * @Description 检查文件名是否重叠
		 * @param filename
		 * @return int
		 */
		public static int checkDoubleFilename(String filename) {
			 File file = new File(".\\");		 
			 
			 for(String printname : file.list()){
				 if(filename.equals(printname)) {
					 return 1;
				 }
			 }
			 return 0;
		}
		
        /**
         * @MethodName checkAccountExist
         * @Description TODO
         * @param accountname
         * @return int
         */
		public static int checkAccountExist(String accountname) {
			 File file = new File(".\\");		 
			 
			 for(String printname : file.list()){
				 if(printname.matches(accountname + ".+")) {
					 return 1;
				 }
			 }
			 return 0;
		}
		
		/**
		 * @MethodName findFilePassword
		 * @Description 找回密码，并重命名文件
		 * @param accountname
		 * @return int
		 */
		public static int findFilePassword(String accountname)
		{
			File file = new File(".\\");		 
			 
			for(String printname : file.list()) {
				 if(printname.matches(accountname + ".+")) {
					 Scanner input = new Scanner(System.in);
					 String newpass = null;
					 boolean match = false;
					
					 do {
							int flag = 0;
							System.out.println("请输入您的密码：");
							newpass  = input.next();
							String passwordErgex = "^(?![0-9]+$)(?![a-zA-Z]+$)[0-9A-Za-z]{6,16}$";             // 含字母和数字
							match = newpass.matches(passwordErgex );
							if(match) {
								flag = 1;
							}
							else {
								CleanConsole.clear();
								System.out.println("密码必须含字母和数字，且必须在6-16位数！");
								match = false;
							}
							
							if(flag == 1) {
								System.out.println("请确认您的密码：");
								String verifypassword  = input.next();
								if(verifypassword.equals(newpass)) {
									break;
								}
								else{
									CleanConsole.clear();
									match = false;
									System.out.println("两次输入不一致！");
								}
							}
					 }while(!match);
					 
					 File thisfileFile = new File(".\\" + printname);
					 thisfileFile.renameTo(new File(accountname + newpass + ".txt"));
					 
					 // 文件里的第一行也要改写
					 accountFileCreateOrOverride(accountname + newpass + ".txt", accountname, newpass);
					 return 1;
				 }
			 }
			return 0;
		}
		
		/**
		 * @MethodName modifyAccount
		 * @Description 修改账户名
		 * @param accountFileName
		 * @param password
		 * @return
		 */
		public static int modifyAccount(String accountFileName, String password)
		{
			 Scanner input = new Scanner(System.in);
			 String newAccount = null;
			 boolean match = false;
				
			 do {
				System.out.println("请输入您的账户名(账户名即为用户手机号，11位数):");
				newAccount  = input.next();
				String accountErgex = "[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]";
				match = newAccount.matches(accountErgex);
				if(match) {
					break;
				}
				else {
					CleanConsole.clear();
					System.out.println("账号必须为11位数且只能为数字，请重新输入！");
				}
			 }while(!match);
					
		    Path source = Paths.get(".\\" + accountFileName);
			try {
				Files.move(source, source.resolveSibling(newAccount + password + ".txt"));
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
				System.out.println("文件操作失败！");
			}
			 
			 // 文件里的第一行也要改写
			 accountFileCreateOrOverride(newAccount + password + ".txt", newAccount, password);
			 return 1;
		}

		// 向文件里写入联系人信息
		public static int InputFile(Contact contact, String accountFileMessage) {
			
			try {
				FileWriter newFile = new FileWriter(accountFileMessage, true);
				BufferedWriter bufferedWriter = new BufferedWriter(newFile);
						
				bufferedWriter.write(contact.getName());
				bufferedWriter.newLine();
				bufferedWriter.write(contact.getGroup());
				bufferedWriter.newLine();
				bufferedWriter.write(contact.getName());
				bufferedWriter.newLine();
				bufferedWriter.write(contact.getSex());
				bufferedWriter.newLine();
				
				ArrayList<String> phoneList = contact.getPhonenumbers();
				for(String str : phoneList) {
					bufferedWriter.write(str + " ");
				}
				bufferedWriter.newLine();
				
				bufferedWriter.write(contact.getEmail());
				bufferedWriter.newLine();
				bufferedWriter.write(contact.getOther());
				bufferedWriter.newLine();
				bufferedWriter.newLine();
				
				bufferedWriter.close();
				newFile.close();
				
				return 1;
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
				return 0;
			}
		}
		
		/**
		 * @MethodName deleteAcoount
		 * @Description 注销账户
		 * @param accountFileMessage
		 * @return int
		 */
		public static int deleteAcoount(String accountFileMessage) {
			File file = new File(accountFileMessage);
			file.delete();
			
			return 1;
		}
		
		/**
		 * @MethodName deleteContact
		 * @Description 删除文件联系人名操作
		 * @param accountFileMessage       文件账户信息
		 * @param name                             删除联系人的名字
		 * @return int                               返回执行情况
		 */
		public static int deleteContact(String accountFileMessage, String name) {
			
			try {
				FileReader fileReader = new FileReader(accountFileMessage);
				BufferedReader bufferedReader = new BufferedReader(fileReader);
				FileWriter fileWriter = new FileWriter("temp.txt");
				BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
				
				// 让文件内容写到另一个文件
				// 每个文件前两行账户信息跳过
				String temp = null;
				temp = bufferedReader.readLine();
				bufferedWriter.write(temp);
				bufferedWriter.newLine();
				temp = bufferedReader.readLine();
				bufferedWriter.newLine();
				
				String str = bufferedReader.readLine();
				int flag = 0;
				do {
					
					if(str == null) {
						break;
					}
					
					if(str.equals(name) == true) {
						flag = 1;
						for(int i = 1; i <= 7; i++) {
							temp = bufferedReader.readLine();
						}
					}
					else {
						bufferedWriter.write(str);
						bufferedWriter.newLine();
						
						for(int i = 1; i <= 7; i++) {
							temp = bufferedReader.readLine();
							bufferedWriter.write(temp);
							bufferedWriter.newLine();
						}
					}
					
					str = bufferedReader.readLine();
				}while(true);
				
				bufferedReader.close();
				bufferedWriter.close();
				fileReader.close();
				fileWriter.close();
				
				// 删除原来的文件，给temp.txt文件重命名
				File file = new File(accountFileMessage);
				file.delete();
			    Path source = Paths.get(".\\temp.txt");
				try {
					Files.move(source, source.resolveSibling(accountFileMessage));
				} catch (IOException e) {
					// TODO Auto-generated catch block
					System.out.println(e.getMessage());
					System.out.println("文件操作失败！");
				}
				
				if(flag == 1) {
					return 1;
				}
				else {
					return 0;
				}
				
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
				return 0;
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
				return 0;
			}
		}
		
		/**
		 * @MethodName modifyContact
		 * @Description 修改联系人信息
		 * @param accountFileMessage   文件账户信息
		 * @param contact        联系人基本信息，是个类
		 * @param name           修改的联系人名字
		 * @return int              返回是否执行成功
		 */
		public static int modifyContact(String accountFileMessage, Contact contact, String name) {
			try {
				FileReader fileReader = new FileReader(accountFileMessage);
				BufferedReader bufferedReader = new BufferedReader(fileReader);
				FileWriter fileWriter = new FileWriter("temp.txt");
				BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
				
				// 让文件内容写到另一个文件
				// 每个文件前两行账户信息跳过
				String temp = null;
				temp = bufferedReader.readLine();
				bufferedWriter.write(temp);
				bufferedWriter.newLine();
				temp = bufferedReader.readLine();
				bufferedWriter.newLine();
				
				String str = bufferedReader.readLine();
				int flag = 0;
				do {
					
					if(str == null) {
						break;
					}
					
					if(str.equals(name) == true) {
						flag = 1;
						for(int i = 1; i <= 7; i++) {
							temp = bufferedReader.readLine();
						}
					}
					else {
						bufferedWriter.write(str);
						bufferedWriter.newLine();
						
						for(int i = 1; i <= 7; i++) {
							temp = bufferedReader.readLine();
							bufferedWriter.write(temp);
							bufferedWriter.newLine();
						}
					}
					
					str = bufferedReader.readLine();
				}while(true);
				
				bufferedReader.close();
				bufferedWriter.close();
				fileReader.close();
				fileWriter.close();
				
				// 上面删除该联系人信息后，现在重新写入修改的信息
				if(flag == 1) {
					InputFile(contact, "temp.txt");
				}
				
				// 删除原来的文件，给temp.txt文件重命名
				File file = new File(accountFileMessage);
				file.delete();
			    Path source = Paths.get(".\\temp.txt");
				try {
					Files.move(source, source.resolveSibling(accountFileMessage));
				} catch (IOException e) {
					// TODO Auto-generated catch block
					System.out.println(e.getMessage());
					System.out.println("文件操作失败！");
				}
				
				if(flag == 1) {
					return 1;
				}
				else {
					return 0;
				}
				
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
				return 0;
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
				return 0;
			}
		}
		
		/**
		 * @MethodName showContact
		 * @Description 显示所有联系人
		 * @param accountFileMessage
		 */
		public static void showContact(String accountFileMessage) {
			ArrayList<String> arrayList = new ArrayList<String>();
			int flag = 0;
			try {
				FileReader fileReader = new FileReader(accountFileMessage);
				BufferedReader bufferedReader = new BufferedReader(fileReader);
				
				// 先要把前两行信息读走
				bufferedReader.readLine();
				bufferedReader.readLine();
				
				String str = null;
				do {
					str = bufferedReader.readLine();
					
					if(str == null) {
						break;
					}
					
					str = bufferedReader.readLine();
					arrayList.add("分组：" + str);
					str = bufferedReader.readLine();
					arrayList.add("姓名：" + str);
					str = bufferedReader.readLine();
					arrayList.add("性别：" + str);
					
					str = bufferedReader.readLine();
					String[] arr = str.split("\\s+");
					for(int k = 0; k < arr.length; k++) {
						arrayList.add("电话" + (k+1) + "：" + arr[k]);
					}
					
					str = bufferedReader.readLine();
					arrayList.add("邮箱：" + str);
					str = bufferedReader.readLine();
					arrayList.add("备注：" + str);
					str = bufferedReader.readLine();
					arrayList.add(str);
					
				}while(true);
					
				flag = 1;	
				bufferedReader.close();
				fileReader.close();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
			}
			
			if(flag == 1) {
				Iterator<String> iterator = arrayList.iterator();
				
				while(iterator.hasNext()) {
					System.out.println(iterator.next());
				}
			}	
		}
		
		/**
		 * @MethodName queryContact
		 * @Description 指定查询联系人
		 * @param accountFileMessage       账户信息
		 * @param name                             查找的名字
		 * @return int                                返回执行的结果
		 */
		public static int queryContact(String accountFileMessage, String name) {
			// 临时的ArrayList，用来暂存读出的信息
			ArrayList<String> arrayList = new ArrayList<String>();
			int flag = 0;
			try {
				FileReader fileReader = new FileReader(accountFileMessage);
				BufferedReader bufferedReader = new BufferedReader(fileReader);
				
				String str = null;
				do {
					str = bufferedReader.readLine();
					
					if(str == null) {
						break;
					}
					
					if(str.equals(name) == true) {
						flag = 1;
						str = bufferedReader.readLine();
						arrayList.add("分组：" + str);
						str = bufferedReader.readLine();
						arrayList.add("姓名：" + str);
						str = bufferedReader.readLine();
						arrayList.add("性别：" + str);
						
						str = bufferedReader.readLine();
						String[] arr = str.split("\\s+");
						for(int k = 0; k < arr.length; k++) {
							arrayList.add("电话" + (k+1) + "：" + arr[k]);
						}
						
						str = bufferedReader.readLine();
						arrayList.add("邮箱：" + str);
						str = bufferedReader.readLine();
						arrayList.add("备注：" + str);
						str = bufferedReader.readLine();
						arrayList.add(str);
					}
					
				}while(true);
				
				bufferedReader.close();
				fileReader.close();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
				return 0;
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
				return 0;
			}
			
			// 输出信息
			if(flag == 1) {
				Iterator<String> iterator = arrayList.iterator();
				
				while(iterator.hasNext()) {
					System.out.println(iterator.next());
				}
				
				return 1;
			}	
			else {
				return 0;
			}
			
		}
		
		/**
		 * @MethodName showGroups
		 * @Description 显示所有分组以及分组里的信息
		 * @param accountFileMessage
		 */
		public static void showGroups(String accountFileMessage) {
			// TODO Auto-generated method stub
			
			// 先把分组文件里的组名读出来
			ArrayList<String> groupList = new ArrayList<String>();
			try {
				FileReader fileReader = new FileReader("groups" + accountFileMessage);
				BufferedReader bufferedReader = new BufferedReader(fileReader);
				
				String str = null;
				do {
					str = bufferedReader.readLine();
					
					if(str == null) {
						break;
					}
					groupList.add(str);
				}while(true);
				
				bufferedReader.close();
				fileReader.close();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
			}
			
			// 在将文件中分组的关键字与前面读出来的一一匹配
			ArrayList<String> contactList = new ArrayList<String>();
			int flag = 0;
			try {
				File file = new File(accountFileMessage);
				FileReader fileReader = new FileReader(accountFileMessage);
				BufferedReader bufferedReader = new BufferedReader(fileReader);
				
				// 先要把前两行信息读走
				bufferedReader.readLine();
				bufferedReader.readLine();
		
				String str = null;
				bufferedReader.mark((int) file.length()+1);
				
				for(int i = 0; i < groupList.size(); i++) {
					contactList.add("********************");
					contactList.add("组名：" + groupList.get(i));
					contactList.add("");
					do {
						str = bufferedReader.readLine();
						
						if(str == null) {
							break;
						}
						
						str = bufferedReader.readLine();
						if(str.equals(groupList.get(i)) == true) {
							flag = 1;
							
							str = bufferedReader.readLine();
							contactList.add("姓名：" + str);
							str = bufferedReader.readLine();
							contactList.add("性别：" + str);
							
							str = bufferedReader.readLine();
							String[] arr = str.split("\\s+");
							for(int k = 0; k < arr.length; k++) {
								contactList.add("电话" + (k+1) + "：" + arr[k]);
							}
							
							str = bufferedReader.readLine();
							contactList.add("邮箱：" + str);
							str = bufferedReader.readLine();
							contactList.add("备注：" + str);
							str = bufferedReader.readLine();
							contactList.add(str);
						}
					}while(true);
					bufferedReader.reset();
				}
			
				bufferedReader.close();
				fileReader.close();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
			}
			
			if(flag == 1) {
				Iterator<String> iterator = contactList.iterator();
				
				while(iterator.hasNext()) {
					System.out.println(iterator.next());
				}
			}	
			
		}
		
		/**
		 * @MethodName queryGroups
		 * @Description                           显示指定分组的信息
		 * @param accountFileMessage     账户信息
		 * @param groupName                  分组名
		 * @return int                              返回执行结果
		 */
		public static int queryGroups(String accountFileMessage, String groupName) {
			// 临时的ArrayList，用来暂存读出的信息
			ArrayList<String> contactList = new ArrayList<String>();
			int flag = 0;
			
			try {
				FileReader fileReader = new FileReader(accountFileMessage);
				BufferedReader bufferedReader = new BufferedReader(fileReader);
				
				// 先要把前两行信息读走
				bufferedReader.readLine();
				bufferedReader.readLine();
		
				String str = null;
				contactList.add("********************");
				contactList.add("组名：" + groupName);
				contactList.add("");
				do {
					str = bufferedReader.readLine();
					
					if(str == null) {
						break;
					}
					
					str = bufferedReader.readLine();
					if(str.equals(groupName) == true) {
						flag = 1;
						
						str = bufferedReader.readLine();
						contactList.add("姓名：" + str);
						str = bufferedReader.readLine();
						contactList.add("性别：" + str);
						
						str = bufferedReader.readLine();
						String[] arr = str.split("\\s+");
						for(int k = 0; k < arr.length; k++) {
							contactList.add("电话" + (k+1) + "：" + arr[k]);
						}
						
						str = bufferedReader.readLine();
						contactList.add("邮箱：" + str);
						str = bufferedReader.readLine();
						contactList.add("备注：" + str);
						str = bufferedReader.readLine();
						contactList.add(str);
					}
				}while(true);

				bufferedReader.close();
				fileReader.close();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
			}
			// 输出信息
			if(flag == 1) {
				Iterator<String> iterator = contactList.iterator();
				
				while(iterator.hasNext()) {
					System.out.println(iterator.next());
				}
				return 1;
			}	
			else {
				return 0;
			}
		}
			
}
