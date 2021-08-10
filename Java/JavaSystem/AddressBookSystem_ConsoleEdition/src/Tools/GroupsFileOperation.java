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
import java.util.Scanner;


/**
 * @ClassName GroupsFileOperation.java
 * @Package Tools
 * @author XHW
 * @date 2019年12月9日
 * @Description 对分组文件的操作
 */
public class GroupsFileOperation {
	
	/**
	 * @MethodName createGroupFile
	 * @Description 创建新的分组文件
	 * @param groups
	 * @param acountMessage
	 * @return int
	 */
	public static int createGroupFile(ArrayList<String> groups, String acountMessage) {
		try {
			FileWriter fileWriter = new FileWriter("groups" + acountMessage, true);
			BufferedWriter bufferedWriter =  new BufferedWriter(fileWriter);
			
			if(groups == null) {
				bufferedWriter.close();
				fileWriter.close();
				return 1;
			}
			
			for(String str : groups) {		
				bufferedWriter.write(str);
				bufferedWriter.newLine();
			}
			
			bufferedWriter.close();
			fileWriter.close();
			return 1;
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());
			return 0;
		}

	}
	
	/**
	 * @MethodName addGroupFile
	 * @Description 增加新的分组
	 * @param groupName
	 * @param acountMessage
	 * @return int
	 */
	public static int addGroupFile(String groupName, String acountMessage) {
		try {
			FileWriter fileWriter = new FileWriter("groups" + acountMessage, true);
			BufferedWriter bufferedWriter =  new BufferedWriter(fileWriter);
			
			bufferedWriter.write(groupName);
			bufferedWriter.newLine();
	
			bufferedWriter.close();
			fileWriter.close();
			return 1;
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());
			return 0;
		}
	}
	
	/**
	 * @MethodName checkGroupExist
	 * @Description 检查分组是否存在
	 * @param groupName
	 * @param acountMessage
	 * @return int
	 */
	public static int checkGroupExist(String groupName, String acountMessage) {
		int flag = 0;
	
		try {
			FileReader fileReader = new FileReader("groups" + acountMessage);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			
			String str = bufferedReader.readLine();
			do {
				
				if(str == null) {
					break;
				}
				
				if(str.equals(groupName) == true) {
					flag = 1;
				}
			
				str = bufferedReader.readLine();
		
			}while(true);
			
			bufferedReader.close();
			fileReader.close();
			
			if(flag == 1) {
				return 1;
			}
			else {
				return 0;
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return 0;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return 0;
		}
		
	}	
	
	/**
	 * @MethodName modifyGroup
	 * @Description 修改分组信息
	 * @param groupName
	 * @param acountMessage
	 * @param newName
	 * @return int
	 */
	public static int modifyGroup(String groupName, String acountMessage, String newName) {
		try {
			FileReader fileReader = new FileReader("groups" + acountMessage);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			FileWriter fileWriter = new FileWriter("groupstemp.txt", true);
			BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
			
			String str = bufferedReader.readLine();
			int flag = 0;
			do {
				
				if(str == null) {
					break;
				}
				
				if(str.equals(groupName) == true) {
					flag = 1;
				}
				else {
					bufferedWriter.write(str);
					bufferedWriter.newLine();
				}
				
				str = bufferedReader.readLine();
			}while(true);
			
			bufferedReader.close();
			bufferedWriter.close();
			fileReader.close();
			fileWriter.close();
			
			// 上面删除该分组信息后，现在重新写入修改的信息
			if(flag == 1) {
				addGroupFile(newName, "temp.txt");
			}
			
			// 删除原来的文件，给groupstemptemp.txt文件重命名
			File file = new File("groups" + acountMessage);
			file.delete();
		    Path source = Paths.get(".\\groupstemp.txt");
			try {
				Files.move(source, source.resolveSibling("groups" + acountMessage));
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
	 * @MethodName deleteContact
	 * @Description 删除分组信息
	 * @param groupName
	 * @param acountMessage
	 * @return int
	 */
	public static int deleteContact(String groupName, String acountMessage) {
		
		try {
			FileReader fileReader = new FileReader("groups" + acountMessage);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			FileWriter fileWriter = new FileWriter("groupstemp.txt", true);
			BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
	
			String str = bufferedReader.readLine();
			int flag = 0;
			do {
				
				if(str == null) {
					break;
				}
				
				if(str.equals(groupName) == true) {
					flag = 1;
				}
				else {
					bufferedWriter.write(str);
					bufferedWriter.newLine();
				}
				
				str = bufferedReader.readLine();
			}while(true);
			
			bufferedReader.close();
			bufferedWriter.close();
			fileReader.close();
			fileWriter.close();
			
			// 删除原来的文件，给groupstemptemp.txt文件重命名
			File file = new File("groups" + acountMessage);
			file.delete();
		    Path source = Paths.get(".\\groupstemp.txt");
			try {
				Files.move(source, source.resolveSibling("groups" + acountMessage));
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
	
	
}
