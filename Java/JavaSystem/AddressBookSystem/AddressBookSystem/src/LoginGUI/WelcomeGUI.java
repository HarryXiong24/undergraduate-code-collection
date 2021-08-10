package LoginGUI;

import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.KeyboardFocusManager;
import AccountFindingGUI.FindingGUI;
import Database.Connection_Database;
import RegistGUI.RegistGUI;
import ToolGUI.CheckCode;
import ToolGUI.CheckCodeWrongGUI;
import java.awt.Color;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTextField;
import javax.swing.JEditorPane;
import javax.swing.JPanel;
import javax.swing.ImageIcon;
import javax.swing.JPasswordField;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.DriverManager;

public class WelcomeGUI implements Connection_Database{

	private JFrame frmXhw;
	private JTextField textField;
	private JPasswordField passwordField;
	private String account;
	private char[] password;
	private String DatabaseName;
	private JTextField textField_1;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					WelcomeGUI window = new WelcomeGUI();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public WelcomeGUI() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	
	private void initialize() {
		frmXhw = new JFrame();
		frmXhw.getContentPane().setBackground(new Color(221, 160, 221));
		frmXhw.getContentPane().setForeground(new Color(255, 255, 255));
		frmXhw.setTitle("XHW多功能通讯录(企业级)");
		frmXhw.setResizable(false);
		frmXhw.setBounds(430, 120, 536, 448);
		frmXhw.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmXhw.setVisible(true);
		frmXhw.getContentPane().setLayout(null);
		
		JEditorPane dtrpnxhw = new JEditorPane();
		dtrpnxhw.setBackground(new Color(221, 160, 221));
		dtrpnxhw.setFont(new Font("宋体", Font.PLAIN, 13));
		dtrpnxhw.setText("@由XHW提供技术支持");
		dtrpnxhw.setBounds(394, 387, 126, 22);
		frmXhw.getContentPane().add(dtrpnxhw);
		
		JPanel panel = new JPanel();
		panel.setBackground(Color.PINK);
		panel.setBounds(0, 0, 530, 100);
		frmXhw.getContentPane().add(panel);
		panel.setLayout(null);
		
		JLabel lblNewLabel_1 = new JLabel("");
		lblNewLabel_1.setIcon(new ImageIcon(".\\素材\\timg.jpg"));
		lblNewLabel_1.setBounds(0, 0, 100, 100);
		panel.add(lblNewLabel_1);
		
		JLabel lblNewLabel_2 = new JLabel("XHW多功能通讯录(企业级)");
		lblNewLabel_2.setFont(new Font("华文行楷", Font.BOLD, 32));
		lblNewLabel_2.setForeground(new Color(255, 0, 0));
		lblNewLabel_2.setBounds(110, 23, 410, 56);
		panel.add(lblNewLabel_2);
		
		JPanel panel_1 = new JPanel();
		panel_1.setBorder(null);
		panel_1.setBackground(new Color(221, 160, 221));
		panel_1.setBounds(33, 99, 473, 242);
		frmXhw.getContentPane().add(panel_1);
		panel_1.setLayout(null);
		
		JPanel panel_2 = new JPanel();
		panel_2.setBackground(Color.CYAN);
		panel_2.setBorder(null);
		panel_2.setBounds(93, 29, 290, 30);
		panel_1.add(panel_2);
		panel_2.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("");
		lblNewLabel.setBounds(10, 0, 30, 30);
		panel_2.add(lblNewLabel);
		lblNewLabel.setIcon(new ImageIcon(".\\素材\\账号1.jpg"));
		
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
		
		textField.setToolTipText("账号");
		textField.setBounds(50, 0, 239, 30);
		panel_2.add(textField);
		textField.setColumns(10);
		
		JPanel panel_3 = new JPanel();
		panel_3.setBackground(Color.ORANGE);
		panel_3.setLayout(null);
		panel_3.setBorder(null);
		panel_3.setBounds(93, 82, 290, 30);
		panel_1.add(panel_3);
		
		JLabel label = new JLabel("");
		label.setIcon(new ImageIcon(".\\素材\\密码1.jpg"));
		label.setBounds(10, 0, 30, 30);
		panel_3.add(label);
		
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
		
		passwordField.setColumns(16);
		passwordField.setBounds(50, 0, 240, 30);
		panel_3.add(passwordField);
		
		JPanel panel_5 = new JPanel();
		panel_5.setLayout(null);
		panel_5.setBorder(null);
		panel_5.setBackground(Color.GREEN);
		panel_5.setBounds(93, 132, 135, 30);
		panel_1.add(panel_5);
		
		JLabel label_1 = new JLabel("");
		label_1.setIcon(new ImageIcon(".\\素材\\验证码1.jpg"));
		label_1.setBounds(10, 0, 30, 30);
		panel_5.add(label_1);
		
		textField_1 = new JTextField();
		textField_1.setBounds(51, 0, 84, 30);
		panel_5.add(textField_1);
		textField_1.setToolTipText("");
		textField_1.setColumns(10);
		
		CheckCode vcode = new CheckCode();
		panel_1.add(vcode);
		vcode.setBounds(283, 122, 94, 40);
		vcode.setVisible(true);
		
		JButton btnNewButton = new JButton("安全登录");
		
		//点击回车等于直接点击提交按钮
		textField_1.getRootPane().setDefaultButton(btnNewButton);
		textField_1.requestFocus();
				
		//提交的事件
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				account = textField.getText();
				password = passwordField.getPassword();
				int flag = 0;
				
				System.out.println(textField_1.getText());
				System.out.println(vcode.getCode());

				//各种情况的判断处理
				if(account.length() == 0)
				{
					flag = 1;
				}
				else if(password.length == 0)
				{
					flag = 2;
				}
				else if(vcode.getCode() == null || vcode.getCode().equals(textField_1.getText()) == false)
				{
					flag = 3;
				}
				else
				{
					flag = Connection_Database();
				}
				
				
				if(flag == 1)
				{
					new AccountNullGUI();
				}
				else if(flag == 2)
				{
					new ToolGUI.PassNullGUI();
				}
				else if(flag == 3)
				{
					new CheckCodeWrongGUI();
				}
				else if(flag == 4)
				{
					new LoginWrongGUI();
				}
				else if(flag == 0)
				{	
					new LoginRightGUI();
				}
				
			}
		});
		
		btnNewButton.setForeground(Color.WHITE);
		btnNewButton.setIcon(new ImageIcon(".\\素材\\登录安全s.jpg"));
		btnNewButton.setFont(new Font("华文行楷", Font.BOLD, 30));
		btnNewButton.setBackground(Color.BLUE);
		btnNewButton.setBounds(133, 192, 205, 50);
		panel_1.add(btnNewButton);
		
		JPanel panel_4 = new JPanel();
		panel_4.setBorder(null);
		panel_4.setBackground(new Color(221, 160, 221));
		panel_4.setBounds(10, 346, 109, 63);
		frmXhw.getContentPane().add(panel_4);
		
		// 点击注册账号,跳转到注册界面
		JButton btnNewButton_1 = new JButton("注册账号");
		btnNewButton_1.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				frmXhw.dispose();
				new RegistGUI();
			}
		});
		
		btnNewButton_1.setBackground(Color.WHITE);
		btnNewButton_1.setFont(new Font("楷体", Font.BOLD, 16));
		panel_4.add(btnNewButton_1);
		
		JButton btnNewButton_2 = new JButton("找回密码");
		
		btnNewButton_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				frmXhw.dispose();
				new FindingGUI();
			}
		});
		
		btnNewButton_2.setBackground(Color.WHITE);
		btnNewButton_2.setFont(new Font("楷体", Font.BOLD, 16));
		panel_4.add(btnNewButton_2);
	}

	@Override
	public int Connection_Database() {
		// TODO Auto-generated method stub
		DatabaseName = "User" + account + new String(password);
		
		final String JDBC_DRIVER="com.microsoft.sqlserver.jdbc.SQLServerDriver";// SQL数据库引擎
		final String DB_URL="jdbc:sqlserver://localhost:1433;DatabaseName=" + DatabaseName;// 注意更换自己的数据库端口和名称
		final String USER="Sa";// 填写登录名
		final String PASS="xhw20000424vxv";// 密码
		
	    try{
			   Class.forName(JDBC_DRIVER);
			   DriverManager.getConnection(DB_URL,USER,PASS);
			   System.out.println("数据库连接成功"); 
			   return 0;
		   } 
		catch(Exception e){
			   e.printStackTrace();
			   System.out.println("连接失败");
			   return 4;
		   }
	}
	

}
