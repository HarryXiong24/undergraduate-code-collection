import dao.ShopMapper;
import entity.Order;
import entity.OrderDetail;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.Test;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class ShopMapperTest {

    // 查询订单客户名称中包括“学”的订单信息
    @Test
    public void testFindList() {
        InputStream inputStream;
        try {
            inputStream = Resources.getResourceAsStream("mybatis.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
            SqlSession sqlSession = sqlSessionFactory.openSession();
            try {
                ShopMapper shopMapper = sqlSession.getMapper(ShopMapper.class);
                List<Order> orders = shopMapper.getAssignedName();
                System.out.println(orders.size());
                System.out.println(orders.get(0).getId());
                System.out.println(orders.get(0).getTotalPrice());
                System.out.println(orders.get(0).getCreateTime());
                System.out.println(orders.get(0).getCustomerName());
                System.out.println(orders.get(0).getCustomerAddress());
            } catch (Exception e) {
                e.printStackTrace();
                sqlSession.rollback();
            } finally {
                sqlSession.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    // 新增一个顾客，并写入顾客购买的物品
    @Test
    public void testInsert() {
        InputStream inputStream;
        try {
            inputStream = Resources.getResourceAsStream("mybatis.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
            SqlSession sqlSession = sqlSessionFactory.openSession();
            try {
                ShopMapper shopMapper = sqlSession.getMapper(ShopMapper.class);

                // 模拟顾客买东西
                Order order = new Order();
                order.setId(8);
                order.setCustomerName("张家方");
                order.setCreateTime(new Date());
                order.setCustomerAddress("Kinds Park");
                order.setTotalPrice(184);

                // 模拟买的商品
                OrderDetail orderDetail1 = new OrderDetail();
                orderDetail1.setOrderId(8);
                orderDetail1.setCount(8);
                orderDetail1.setProductName("卫龙");
                orderDetail1.setProductType("食品");
                orderDetail1.setPrice(20);

                OrderDetail orderDetail2 = new OrderDetail();
                orderDetail2.setOrderId(8);
                orderDetail2.setCount(20);
                orderDetail2.setProductName("牙刷");
                orderDetail2.setProductType("生活用品");
                orderDetail2.setPrice(40);

                OrderDetail orderDetail3 = new OrderDetail();
                orderDetail3.setOrderId(8);
                orderDetail3.setCount(20);
                orderDetail3.setProductName("牙膏");
                orderDetail3.setProductType("生活用品");
                orderDetail3.setPrice(40);

                // 构建一个List，方便后面的插入
                List<OrderDetail> list = new ArrayList<OrderDetail>();
                list.add(orderDetail1);
                list.add(orderDetail2);
                list.add(orderDetail3);

                shopMapper.insertOrder(order);
                for( OrderDetail item : list) {
                    shopMapper.insertOrderDetail(item);
                }

                sqlSession.commit();

            } catch (Exception e) {
                e.printStackTrace();
                sqlSession.rollback();
            } finally {
                sqlSession.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    // 删除一个顾客，并删除该顾客的购买信息
    @Test
    public void testDelete() {
        InputStream inputStream;
        try {
            inputStream = Resources.getResourceAsStream("mybatis.xml");
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
            SqlSession sqlSession = sqlSessionFactory.openSession();
            try {
                ShopMapper shopMapper = sqlSession.getMapper(ShopMapper.class);

                // 该变量表示要删除的ID
                int delId = 8;

                // 这里顺序不能反，因为有外键约束
                shopMapper.delOrderDetail(delId);
                int ret = shopMapper.delOrder(delId);

                sqlSession.commit();
                System.out.println("受影响的行数："+ret);

            } catch (Exception e) {
                e.printStackTrace();
                sqlSession.rollback();
            } finally {
                sqlSession.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
