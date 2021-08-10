import com.wjy.pojo.Books;
import com.wjy.pojo.User;
import com.wjy.service.UserMapperService;
import com.wjy.service.bookservice;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import java.util.List;

public class test {
    @Test
    public void test(){
        ApplicationContext context = new ClassPathXmlApplicationContext("application.xml");
        bookservice bookserviceimpl= (com.wjy.service.bookserviceimpl) context.getBean("bookserviceimpl");
        List<Books> list=bookserviceimpl.selectbook();
        for (Books books : list) {
            System.out.println(books.toString());
        }
    }
    @Test
     public void test1(){
         ApplicationContext context = new ClassPathXmlApplicationContext("application.xml");
         UserMapperService userMapperService= (UserMapperService) context.getBean("UserMapperServiceimple");
         User user=new User();
         user.setUsername("zhj");
         user.setPassword("52013114");
         User user1=new User();
         user1= userMapperService.returnuserr(user);
         System.out.println(user1);
     }
}
