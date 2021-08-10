package Preparing;

import Tools.AccountOperation;
import Tools.CleanConsole;
import Tools.FileOperation;

/**
 * @ClassName Regist.java
 * @Package Preparing
 * @author XHW
 * @time 下午9:28:47
 * @Description 进行账户注册操作
 */
public class Regist extends AccountOperation{
	
	@Override
	public void regist() {
		// TODO Auto-generated method stub
		accountVerify();
		doublepasswordVerify();
		
		int doublefile = FileOperation.checkDoubleFilename(getAccountFilename());
		if(doublefile == 1)
		{
			System.out.println("账户已经注册！");
			CleanConsole.clear();
			regist();
		}
		else
		{
			FileOperation.accountFileCreateOrOverride(getAccountFilename(), getAccount(), getPassword());
			System.out.println("注册成功！");
			CleanConsole.clear();
			Welcome.welcome();
		}
		
	}
}
