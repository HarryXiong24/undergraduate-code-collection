import javax.swing.SwingUtilities;
import java.awt.BorderLayout;
import javax.swing.DefaultListModel;
import javax.swing.JPanel;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.ListModel;
import java.awt.Rectangle;
import javax.swing.JList;
import javax.swing.JScrollPane;

public class Menu extends JFrame {
	private JPanel jContentPane = null;
	private JTextArea jTextArea = null;
	private JList jList = null;
	private JScrollPane jScrollPane = null;
	private JScrollPane jScrollPane1 = null;
	private JList jList1 = null;
	private JTextArea jTextArea1 = null;

	private JTextArea getJTextArea() {
		if (jTextArea == null) {
			jTextArea = new JTextArea();
			jTextArea.setBounds(new Rectangle(12, 7, 95, 71));
		}
		return jTextArea;
	}

	private JList getJList() {
		if (jList == null) {
			jList = new JList();
			jList.setBounds(new Rectangle(8, 92, 106, 71));
			DefaultListModel listModel = new DefaultListModel();
			listModel.addElement("22222");
			listModel.addElement("33333333");
			listModel.addElement("55555555555555");
			listModel.addElement("8888888888");
			listModel.addElement("88888888");
			listModel.addElement("999999999");
			jList.setModel(listModel);
		}
		return jList;
	}

	private JScrollPane getJScrollPane() {
		if (jScrollPane == null) {
			jScrollPane = new JScrollPane();
			jScrollPane.setBounds(new Rectangle(143, 7, 122, 75));
			jScrollPane.setViewportView(getJTextArea1());
		}
		return jScrollPane;
	}

	private JScrollPane getJScrollPane1() {
		if (jScrollPane1 == null) {
			jScrollPane1 = new JScrollPane();
			jScrollPane1.setBounds(new Rectangle(142, 96, 128, 68));
			jScrollPane1.setViewportView(getJList1());
		}
		return jScrollPane1;
	}

	private JList getJList1() {
		if (jList1 == null) {
			jList1 = new JList();
			DefaultListModel listModel = new DefaultListModel();
			listModel.addElement("22222");
			listModel.addElement("33333333");
			listModel.addElement("8888888888888888888888888888");
			listModel.addElement("8888888888");
			listModel.addElement("88888888");
			listModel.addElement("999999999");
			jList1.setModel(listModel);
		}
		return jList1;
	}

	private JTextArea getJTextArea1() {
		if (jTextArea1 == null) {
			jTextArea1 = new JTextArea();
		}
		return jTextArea1;
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				Menu thisClass = new Menu();
				thisClass.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				thisClass.setVisible(true);
			}
		});
	}

	public Menu() {
		super();
		initialize();
	}

	private void initialize() {
		this.setSize(300, 200);
		this.setContentPane(getJContentPane());
		this.setTitle("JFrame");
	}

	private JPanel getJContentPane() {
		if (jContentPane == null) {
			jContentPane = new JPanel();
			jContentPane.setLayout(null);
			jContentPane.add(getJTextArea(), null);
			jContentPane.add(getJList(), null);
			jContentPane.add(getJScrollPane(), null);
			jContentPane.add(getJScrollPane1(), null);
		}
		return jContentPane;
	}
}