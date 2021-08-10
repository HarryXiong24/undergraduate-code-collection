package dao;

import entity.Order;
import entity.OrderDetail;

import java.util.List;

public interface ShopMapper {
    // 新增一个顾客
    public void insertOrder(Order order);
    // 删除一个顾客
    public int delOrder(int id);
    // 查询所有顾客
    public List<Order> getOrder();
    // 查询有“学”的顾客
    public List<Order> getAssignedName();

    // 新增一条购物记录
    public void insertOrderDetail(OrderDetail orderDetail);
    // 删除一条购物记录
    public int delOrderDetail(int id);
}
