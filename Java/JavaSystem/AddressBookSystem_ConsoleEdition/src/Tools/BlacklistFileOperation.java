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

public class BlacklistFileOperation {
	
	/**
	 * @Method CreateBlacklistFile
	 * @Class BlacklistFileOperation
	 * @Description 创建黑名单文件
	 * @param accountMessage
	 */
	public static void CreateBlacklistFile(String  accountFileMessage) {
		try {
			FileWriter newFile = new FileWriter("Blacklist" +  accountFileMessage, true);
			newFile.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());
			System.out.println("文件创建出错！");
		}
	}
	
	/**
	 * @Method addToBlacklistFile
	 * @Class BlacklistFileOperation
	 * @Description 向黑名单里添加联系人，并在白名单里删除该联系人
	 * @param accountFileMessage
	 * @param name
	 * @return
	 */
	public static int addToBlacklistFile(String accountFileMessage, String name) {
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
					arrayList.add(str);
					str = bufferedReader.readLine();
					arrayList.add(str);
					str = bufferedReader.readLine();
					arrayList.add( str);
					str = bufferedReader.readLine();
					arrayList.add(str);
					str = bufferedReader.readLine();
					arrayList.add(str);
					str = bufferedReader.readLine();
					arrayList.add(str);
					str = bufferedReader.readLine();
					arrayList.add(str);
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
		
		if(flag == 1) {
			try {
				FileWriter newFile = new FileWriter("Blacklist" +  accountFileMessage, true);
				BufferedWriter bufferedWriter = new BufferedWriter(newFile);
				
				Iterator<String> iterator = arrayList.iterator();
				
				while(iterator.hasNext()) {
					bufferedWriter.write(iterator.next());
					bufferedWriter.newLine();
				}
				
				FileOperation.deleteContact(accountFileMessage, name);
				
				bufferedWriter.close();
				newFile.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			return 1;
		}	
		else {
			return 0;
		}
		
	}
	
	/**
	 * @Method removeFromBlacklist
	 * @Class BlacklistFileOperation
	 * @Description 将黑名单里的联系人移回白名单
	 * @param accountFileMessage
	 * @param name
	 * @return
	 */
	public static int removeFromBlacklistFile(String accountFileMessage, String name) {
		
		ArrayList<String> arrayList = new ArrayList<String>();
		int flag = 0;
		
		try {
			FileReader fileReader = new FileReader("Blacklist" + accountFileMessage);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			FileWriter fileWriter = new FileWriter("temp.txt");
			BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
			
			// 让文件内容写到另一个文件
			String temp = null;
			
			String str = bufferedReader.readLine();
			do {
				
				if(str == null) {
					break;
				}
				
				if(str.equals(name) == true) {
					flag = 1;
					for(int i = 1; i <= 7; i++) {
						arrayList.add(bufferedReader.readLine());
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
			File file = new File("Blacklist" + accountFileMessage);
			file.delete();
		    Path source = Paths.get(".\\temp.txt");
			try {
				Files.move(source, source.resolveSibling("Blacklist" + accountFileMessage));
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
				System.out.println("文件操作失败！");
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
		
		if(flag == 1) {
			try {
				FileWriter newFile = new FileWriter(accountFileMessage, true);
				BufferedWriter bufferedWriter = new BufferedWriter(newFile);
				
				Iterator<String> iterator = arrayList.iterator();
				
				bufferedWriter.write(name);
				bufferedWriter.newLine();
				while(iterator.hasNext()) {
					bufferedWriter.write(iterator.next());
					bufferedWriter.newLine();
				}
				
				bufferedWriter.close();
				newFile.close();
				flag = 1;
				
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println(e.getMessage());
				return 0;
			}
			return 1;
		}
		else {
			return 0;
		}
	}
	
	public static void showBlacklist(String accountFileMessage) {
		ArrayList<String> arrayList = new ArrayList<String>();
		int flag = 0;
		try {
			FileReader fileReader = new FileReader("Blacklist" + accountFileMessage);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			
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
	
}
