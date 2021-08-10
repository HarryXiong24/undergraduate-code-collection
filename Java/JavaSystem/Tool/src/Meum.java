import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.KeyStroke;

/*
 * 模仿Eclipse菜单栏结构
 */
public class Meum extends JFrame {
    String[][] menuNameMnemonics = { { "File", "f" }, { "Edit", "e" },
            { "Source", "s" }, { "Refactor", "t" }, { "Navigate", "n" },
            { "Search", "a" }, { "Project", "p" }, { "Run", "r" }, { "Window", "w" }, { "Help", "h" } };
    JMenuBar menuBar;

    public Meum() {
        menuBar = new JMenuBar();
        setJMenuBar(menuBar);
        
        for (String[] menuNameMnemonic : menuNameMnemonics) {
            menuBar.add(createMenu(menuNameMnemonic[0], menuNameMnemonic[1]));
        }
        
        // 为File添加子菜单和菜单项
        JMenu fileMenu = getMenu("File");
        fileMenu.add(createMenuNamedNew());
        
        fileMenu.add(createMenuItem("Open File", null, null,null));
        fileMenu.addSeparator();
        
        fileMenu.add(createMenuItem("Close", "c", null, KeyStroke.getKeyStroke('W', InputEvent.CTRL_MASK)));
        fileMenu.add(createMenuItem("Close All", "l", null, KeyStroke.getKeyStroke(KeyEvent.VK_W, InputEvent.CTRL_MASK | InputEvent.SHIFT_MASK)));
        fileMenu.addSeparator();
        fileMenu.add(createMenuItem("Save", "s", new ImageIcon("resources\\JMenuDemo\\icon\\Save.png"), KeyStroke.getKeyStroke(KeyEvent.VK_S, InputEvent.CTRL_MASK)));
        fileMenu.add(createMenuItem("Save As", "a", new ImageIcon("resources\\JMenuDemo\\icon\\SaveAs.png"), null));
        fileMenu.add(createMenuItem("Save All", "e", new ImageIcon("resources\\JMenuDemo\\icon\\SaveAll.png"), KeyStroke.getKeyStroke(KeyEvent.VK_S, InputEvent.CTRL_MASK | InputEvent.SHIFT_MASK)));
        fileMenu.add(createMenuItem("Revert", "t", null, null));
        fileMenu.addSeparator();
        
        JMenuItem menuNamedMove = createMenuItem("Move", "v", null, KeyStroke.getKeyStroke(KeyEvent.VK_V, InputEvent.CTRL_MASK | InputEvent.SHIFT_MASK));
        menuNamedMove.setEnabled(false);
        fileMenu.add(menuNamedMove);
        
        JMenuItem menuNamedRename = createMenuItem("Rename", "m", new ImageIcon("resources\\JMenuDemo\\icon\\Rename.png"), KeyStroke.getKeyStroke("F2"));
        menuNamedRename.setEnabled(false);
        fileMenu.add(menuNamedRename);
        
        fileMenu.add(createMenuItem("Refresh", "f", new ImageIcon("resources\\JMenuDemo\\icon\\Refresh.png"), KeyStroke.getKeyStroke("F5")));
        
        JMenu menuNamedConvert = createMenuNamedConvert();
        fileMenu.add(menuNamedConvert);//添加New菜单
        
        fileMenu.addSeparator();
        fileMenu.add(createMenuItem("Print", "p", new ImageIcon("resources\\JMenuDemo\\icon\\Print.png"), KeyStroke.getKeyStroke(KeyEvent.VK_P, InputEvent.CTRL_MASK)));
        fileMenu.addSeparator();
        
        JMenu menuNamedSwitch = createMenu("Switch WorkSpsace", "w");
        menuNamedSwitch.add(createMenuItem("Other", "o", null, null));
        fileMenu.add(menuNamedSwitch);
        
        fileMenu.add(createMenuItem("Restart", null, null, null));
        fileMenu.addSeparator();
        fileMenu.add(createMenuItem("Import", "i", new ImageIcon("resources\\JMenuDemo\\icon\\Import.png"), null));
        fileMenu.add(createMenuItem("Export", "o", new ImageIcon("resources\\JMenuDemo\\icon\\Export.png"), null));
        fileMenu.addSeparator();
        fileMenu.add(createMenuItem("Properties", "r", null, KeyStroke.getKeyStroke(KeyEvent.VK_ENTER, InputEvent.ALT_MASK)));
        fileMenu.addSeparator();
        fileMenu.add(createMenuItem("Exit", "x", null, null));
    }

    private JMenu createMenuNamedNew() {
        /*
         * * 创建名称为New的menu
         */
        JMenu menu = createMenu("New", "n");        
        menu.add(createMenuItem("JavaProject", null, new ImageIcon("resources\\JMenuDemo\\icon\\JavaProject.gif"), null));
        menu.add(createMenuItem("Project", null, new ImageIcon("resources\\JMenuDemo\\icon\\Project.gif"), null));
        menu.add(createMenuItem("Package", null, new ImageIcon("resources\\JMenuDemo\\icon\\Package.gif"), null));
        menu.add(createMenuItem("Class", null, new ImageIcon("resources\\JMenuDemo\\icon\\Class.gif"), null));
        menu.add(createMenuItem("Interface", null, new ImageIcon("resources\\JMenuDemo\\icon\\Interface.gif"), null));
        menu.add(createMenuItem("Enum", null, new ImageIcon("resources\\JMenuDemo\\icon\\Enum.gif"), null));
        menu.add(createMenuItem("Annotation", null, new ImageIcon("resources\\JMenuDemo\\icon\\Annotation.gif"), null));
        menu.add(createMenuItem("SourceFolder", null, new ImageIcon("resources\\JMenuDemo\\icon\\SourceFolder.gif"), null));
        menu.add(createMenuItem("JavaWorkingSet", null, new ImageIcon("resources\\JMenuDemo\\icon\\JavaWorkingSet.gif"), null));
        menu.add(createMenuItem("Folder", null, new ImageIcon("resources\\JMenuDemo\\icon\\Folder.gif"), null));
        menu.add(createMenuItem("File", null, new ImageIcon("resources\\JMenuDemo\\icon\\File.gif"), null));
        menu.add(createMenuItem("UntitledTextFile", null, new ImageIcon("resources\\JMenuDemo\\icon\\UntitledTextFile.gif"), null));
        menu.add(createMenuItem("JunitTestCase", null, new ImageIcon("resources\\JMenuDemo\\icon\\JunitTestCase.gif"), null));
        menu.add(createMenuItem("Task", null, new ImageIcon("resources\\JMenuDemo\\icon\\Task.gif"), null));
        menu.add(createMenuItem("Example", null, new ImageIcon("resources\\JMenuDemo\\icon\\Example.gif"), null));
        menu.add(createMenuItem("Other", null, new ImageIcon("resources\\JMenuDemo\\icon\\Other.gif"), null));
        return menu;
    }
    
    private JMenu createMenuNamedConvert() {
        /*
         * 创建名称为Convert的menu
         */
        JMenu menu = createMenu("Convert Line Delimiters to", "v");
        menu.add(createMenuItem("Windows (CRLF, \\r\\n, 0D0A, xx)[default]", "w", null, null));
        menu.add(createMenuItem("Unix (LF, \\n, 0A, xx)", "n", null, null));
        return menu;
    }

    private JMenu getMenu(String menuName) {
        /*
         * 根据名称从menuBar中查找menu并返回
         */
        JMenu menu = null;
        for (int i = 0; i < menuBar.getMenuCount(); i++) {
            menu = menuBar.getMenu(i);
            if (menu.getText().equals(menuName))
                return menu;
        }
        return null;
    }

    private JMenu createMenu(String name, String mnemonic) {
        /*
         * 根据名称和快捷键创建menu并添加到menuBar
         */
        JMenu menu = new JMenu(name);
        if (mnemonic != null)
            menu.setMnemonic(mnemonic.toCharArray()[0]);
        return menu;
    }

    private JMenuItem createMenuItem(String name, String mnemonic, Icon icon, KeyStroke keyStroke) {
        /*
         * 根据名称和快捷键创建menu并添加到menuBar
         */
        JMenuItem menuItem = new JMenuItem(name, icon);
        if (mnemonic != null)
            menuItem.setMnemonic(mnemonic.toCharArray()[0]);
        if (keyStroke != null)
            menuItem.setAccelerator(keyStroke);
        return menuItem;
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        // 创建窗体
        Meum frame = new Meum();
        //指定标题
        frame.setTitle("JMenuDemo");
        //指定icno
        frame.setIconImage(new ImageIcon("resources\\JMenuDemo\\icon\\Eclipse.png").getImage());
        // 关闭窗体后退出程序
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // 自动适配所有控件大小
        frame.setSize(frame.getPreferredSize().width, 200);
        //frame.pack();
        // 设置窗体位置在屏幕中央
        frame.setLocationRelativeTo(null);
        // 显示窗体
        frame.setVisible(true);
    }
}