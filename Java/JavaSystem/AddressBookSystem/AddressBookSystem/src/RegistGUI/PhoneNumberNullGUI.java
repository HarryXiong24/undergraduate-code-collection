package RegistGUI;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.border.EmptyBorder;

public class PhoneNumberNullGUI extends JDialog {

	private final JPanel contentPanel = new JPanel();

	/**
	 * Launch the application.
	 */
	/*public static void main(String[] args) {
		try {
			AccountNullGUI dialog = new AccountNullGUI();
			dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
			dialog.setVisible(true);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}*/

	/**
	 * Create the dialog.
	 */
	public PhoneNumberNullGUI() {
		setAlwaysOnTop(true);
		getContentPane().setBackground(new Color(0, 0, 0));
		setBackground(new Color(0, 0, 0));
		setTitle("XHW多功能通讯录(企业级)");
		setBounds(540, 260, 331, 186);
		setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
		setVisible(true);
		
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBackground(new Color(245, 222, 179));
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		{
			JTextArea textArea = new JTextArea();
			textArea.setEditable(false);
			textArea.setBackground(new Color(245, 222, 179));
			textArea.setFont(new Font("宋体", Font.BOLD, 16));
			textArea.setBounds(112, 28, 149, 47);
			textArea.setText("手机号不能为空！\r\n请确认后重试！");
			textArea.setColumns(10);
			contentPanel.add(textArea);
		}
		{
			JLabel label = new JLabel("");
			label.setIcon(new ImageIcon(".\\素材\\感叹号1.jpg"));
			label.setBounds(39, 10, 50, 77);
			contentPanel.add(label);
		}
		{
			JPanel buttonPane = new JPanel();
			buttonPane.setLayout(new FlowLayout(FlowLayout.RIGHT));
			getContentPane().add(buttonPane, BorderLayout.SOUTH);
			{
				JButton okButton = new JButton("返回");
				okButton.setBackground(new Color(0, 255, 255));
				
				// 点击要处理的事件
				okButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						dispose();
					}
				});
				
				okButton.setActionCommand("OK");
				buttonPane.add(okButton);
				getRootPane().setDefaultButton(okButton);
			}
		}
	}

}
