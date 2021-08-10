package Tools;

import java.awt.AWTException;
import java.awt.Robot;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;

/**
 * @ClassName CleanConsole.java
 * @Package Tools
 * @author XHW
 * @time 下午9:39:06
 * @Description 实现清屏操作
 */
public class CleanConsole {
	/**
	 * @MethodName clear
	 * @param 
	 * @return void
	 * @throws 
	 * @Description 调用Robot类，模拟鼠标在控制台单机右键选择clear的功能
	 */
	public static void clear() {
		Robot r;
		try {
			r = new Robot();
			r.delay(500);       
	        r.mousePress(InputEvent.BUTTON3_MASK);       // 按下鼠标右键
	        r.mouseRelease(InputEvent.BUTTON3_MASK);    // 释放鼠标右键       
	        r.keyPress(KeyEvent.VK_CONTROL);             // 按下Ctrl键
	        r.keyPress(KeyEvent.VK_R);                    // 按下R键
	        r.keyRelease(KeyEvent.VK_R);                  // 释放R键
	        r.keyRelease(KeyEvent.VK_CONTROL);            // 释放Ctrl键     
	        r.delay(500);       
		} catch (AWTException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("控制台错误！请检查控制台！");
		}  
	}
}
