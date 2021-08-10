package Preparing;

import Logined.Function;
import Tools.AccountOperation;
import Tools.BlacklistFileOperation;
import Tools.CleanConsole;
import Tools.FileOperation;
import Tools.GroupsFileOperation;

/**
 * @ClassName Login.java
 * @Package Preparing
 * @author XHW
 * @time 下午9:30:17
 * @Description 进行账户登录操作
 */
class Login extends AccountOperation {

	@Override
	/**
	 * @MethodName login
	 * @see Tools.AccountOperation#login()
	 * @param 
	 * @return 
	 * @throws 
	 * @Description 进行登录操作，带有密码输入次数功能
	 */
	public void login() {
		// TODO Auto-generated method stub
		accountVerify();
		int flag1 = FileOperation.checkAccountExist(getAccount());
		
		if(flag1 == 0)
		{
			System.out.println("没有这个账户！");
			CleanConsole.clear();
			Welcome.welcome();
		}
		else {
			int flag2 = passwordVerify();
			
			if(flag2 == 0) {
				System.out.println("输入密码次数已用尽！");
				CleanConsole.clear();
				Welcome.welcome();
			}
			else {
				CleanConsole.clear();
				Function function = new Function();
				function.setAccountFileMessage(getAccountFilename());		
				// 登录成功就要创建出分组，不管是否有分组内容
				GroupsFileOperation.createGroupFile(null, getAccountFilename());
				// 登录成功就要创建出黑名单，不管是否有黑名单内容
				BlacklistFileOperation.CreateBlacklistFile(getAccountFilename());
				function.guide();
			}	
		}
	}
}
