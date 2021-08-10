import edu.cuit.cs.User;
import edu.cuit.cs.UserService;
import org.junit.Test;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public  class DemoTest {
    @Test
     public void testaop(){
        ClassPathXmlApplicationContext ctx = new ClassPathXmlApplicationContext("spring-config.xml");

        // 测试用户服务aop过程
        UserService userService=ctx.getBean(UserService.class);
        User user = new User("jack","123456");
        //userService.addUser(user);
        System.out.println("======================================================================");
        userService.deleteUser(user);

        ctx.close();
    }
}
