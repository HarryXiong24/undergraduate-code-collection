package RegistGUI;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.KeyboardFocusManager;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JEditorPane;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

import LoginGUI.WelcomeGUI;
import ToolGUI.BothPassNull;
import ToolGUI.PassNullGUI;

import javax.swing.JTextField;
import javax.swing.JPasswordField;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import Function.User;

public class RegistGUI {

	private JFrame frame;
	private JTextField textField;
	private JPasswordField passwordField;
	private JPasswordField passwordField_1;
	private String account;
	private char[] newPass;
	private char[] verifyPass;

	/**
	 * Launch the application.
	 */
	/*public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					HUI window = new HUI();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}*/

	/**
	 * Create the application.
	 */
	public RegistGUI() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.getContentPane().setBackground(new Color(245, 222, 179));
		frame.setBounds(430, 120, 536, 448);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		frame.setVisible(true);
		
		JPanel panel = new JPanel();
		panel.setBounds(0, 0, 530, 100);
		frame.getContentPane().add(panel);
		panel.setBackground(Color.PINK);
		panel.setLayout(null);
		
		JLabel label = new JLabel("");
		label.setIcon(new ImageIcon("D:\\编程\\Java\\Java\\JavaSystem\\AddressBookSystem\\素材\\timg.jpg"));
		label.setBounds(0, 0, 100, 100);
		panel.add(label);
		
		JLabel label_1 = new JLabel("欢迎进行新用户注册！");
		label_1.setBounds(101, 19, 419, 56);
		label_1.setHorizontalAlignment(SwingConstants.CENTER);
		label_1.setForeground(Color.RED);
		label_1.setFont(new Font("华文行楷", Font.BOLD, 32));
		panel.add(label_1);
		
		JEditorPane editorPane_1 = new JEditorPane();
		editorPane_1.setText("@由XHW提供技术支持");
		editorPane_1.setFont(new Font("宋体", Font.PLAIN, 13));
		editorPane_1.setBackground(new Color(245, 222, 179));
		editorPane_1.setBounds(394, 387, 126, 22);
		panel.add(editorPane_1);
		
		JPanel panel_1 = new JPanel();
		panel_1.setBounds(71, 110, 379, 246);
		frame.getContentPane().add(panel_1);
		panel_1.setLayout(null);
		panel_1.setBackground(new Color(240, 230, 140));
		
		JPanel panel_2 = new JPanel();
		panel_2.setLayout(null);
		panel_2.setBackground(new Color(255, 240, 245));
		panel_2.setBounds(40, 45, 290, 28);
		panel_1.add(panel_2);
		
		JLabel label_2 = new JLabel("手机号");
		label_2.setHorizontalAlignment(SwingConstants.CENTER);
		label_2.setFont(new Font("楷体", Font.BOLD, 14));
		label_2.setBackground(Color.YELLOW);
		label_2.setBounds(0, 0, 66, 28);
		panel_2.add(label_2);
		
		textField = new JTextField();	
			
		//点击回车光标跳转到下一个框
		textField.addKeyListener(new KeyAdapter()
		{
           public void keyPressed(KeyEvent e)
           {
               if (e.getKeyCode() == KeyEvent.VK_ENTER)
               {
                   e.consume();
                   KeyboardFocusManager.getCurrentKeyboardFocusManager().focusNextComponent();
               }
           }
        });
		
		textField.setColumns(11);
		textField.setBounds(67, 0, 223, 28);
		panel_2.add(textField);
		
		JPanel panel_3 = new JPanel();
		panel_3.setLayout(null);
		panel_3.setBackground(new Color(255, 240, 245));
		panel_3.setBounds(40, 99, 290, 28);
		panel_1.add(panel_3);
		
		JLabel label_3 = new JLabel("输入密码");
		label_3.setHorizontalAlignment(SwingConstants.CENTER);
		label_3.setFont(new Font("楷体", Font.BOLD, 14));
		label_3.setBackground(Color.YELLOW);
		label_3.setBounds(0, 0, 66, 28);
		panel_3.add(label_3);
		
		passwordField = new JPasswordField();	
		
		//点击回车光标跳转到下一个框
		passwordField.addKeyListener(new KeyAdapter()
		{
           public void keyPressed(KeyEvent e)
           {
               if (e.getKeyCode() == KeyEvent.VK_ENTER)
               {
                   e.consume();
                   KeyboardFocusManager.getCurrentKeyboardFocusManager().focusNextComponent();
               }
           }
        });
		
		passwordField.setBounds(67, 0, 223, 28);
		panel_3.add(passwordField);
		
		JPanel panel_4 = new JPanel();
		panel_4.setLayout(null);
		panel_4.setBackground(new Color(255, 240, 245));
		panel_4.setBounds(40, 149, 290, 28);
		panel_1.add(panel_4);
		
		JLabel label_4 = new JLabel("确认密码");
		label_4.setHorizontalAlignment(SwingConstants.CENTER);
		label_4.setFont(new Font("楷体", Font.BOLD, 14));
		label_4.setBackground(Color.YELLOW);
		label_4.setBounds(0, 0, 66, 28);
		panel_4.add(label_4);
		
		passwordField_1 = new JPasswordField();
		passwordField_1.setBounds(67, 0, 223, 28);
		panel_4.add(passwordField_1);
		
		JButton button = new JButton("提交");
		
		//点击回车等于直接点击提交按钮
		passwordField_1.getRootPane().setDefaultButton(button);
		passwordField_1.requestFocus();
		
		//提交的事件
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				account = textField.getText();
				newPass = passwordField.getPassword();
				verifyPass = passwordField_1.getPassword();
				int flag = 0;
				
				//各种情况的判断处理
				if(account.length() == 0)
				{
					flag = 1;
				}
				else if(newPass.length == 0 || verifyPass.length == 0)
				{
					flag = 2;
				}
				else 
				{
					if(newPass.length != verifyPass.length)
					{
						flag = 3;
					}
					else
					{
						for(int i = 0; i < newPass.length && i < verifyPass.length; i++)
						{
							if(verifyPass[i] != newPass[i])
							{
								flag = 3;
								break;
							}
						}
					}
				}
				
				if(flag == 1)
				{
					new PhoneNumberNullGUI();
				}
				else if(flag == 2)
				{
					new BothPassNull();
				}
				else if(flag == 3)
				{
					new RegistVerifyWrongGUI();
				}
				else if(flag == 0)
				{	
					String Password = new String(verifyPass);
					User NewUser = new User(account, Password);
					flag = NewUser.Create_NewDatabase();
					if(flag == 4)
					{
						new RegistWrongGUI();
					}
					else
					{
						new RegistRightGUI();
					}
				}
				
			}
		});
		
		button.setFont(new Font("楷体", Font.BOLD, 18));
		button.setBackground(new Color(0, 191, 255));
		button.setBounds(107, 202, 176, 34);
		panel_1.add(button);
		
		JEditorPane editorPane = new JEditorPane();
		editorPane.setText("@由XHW提供技术支持");
		editorPane.setFont(new Font("宋体", Font.PLAIN, 13));
		editorPane.setBackground(new Color(245, 222, 179));
		editorPane.setBounds(394, 387, 126, 22);
		frame.getContentPane().add(editorPane);
		
		JButton button_1 = new JButton("返回登录");
		
		// 返回登录菜单的事件
		button_1.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				frame.dispose();
				new WelcomeGUI();
			}
		});
		
		button_1.setFont(new Font("楷体", Font.BOLD, 14));
		button_1.setBackground(new Color(245, 222, 179));
		button_1.setBounds(0, 377, 101, 32);
		frame.getContentPane().add(button_1);
	}
}
