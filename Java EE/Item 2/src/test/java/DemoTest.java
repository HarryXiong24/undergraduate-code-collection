import com.xhw.entity.User;
import org.junit.Test;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public  class DemoTest {
    @Test
     public void test(){
        ClassPathXmlApplicationContext ctx = new ClassPathXmlApplicationContext("spring-config.xml");

        // 测试用户服务aop过程
        User user = ctx.getBean("user", User.class);

        user.SayHello();

        ctx.close();
    }
}
