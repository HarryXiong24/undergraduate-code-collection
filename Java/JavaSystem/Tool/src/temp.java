import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

class temp{
	public static void getData(String path) {
	    try {
	        //获取图像资源，转成BufferedImage对象
	        BufferedImage bimg = ImageIO.read(new File(path));
	        //创建一个二维数组，用来存放图像每一个像素位置的颜色值
	        int[][] data = new int[bimg.getWidth()][bimg.getHeight()];
	        //以高度为范围，逐列扫描图像，存进数组对应位置
	        for (int i = 0; i < bimg.getWidth(); i++) {
	            for (int j = 0; j < bimg.getHeight(); j++) {
	                data[i][j] = bimg.getRGB(i, j);//得到的是sRGB值，4字节
	            }
	        }
	        compressImg(bimg.getWidth(),bimg.getHeight(),data,6);
	    } catch (IOException e) {
	        e.printStackTrace();
	    }
	}
	
	public static void compressImg(int width,int height, int [][] data ,int x){
	    //将数组旋转90°输出，实现逐行输出图像
	    for (int i = 0; i < height; i+=x) {
	        for (int j = 0; j < width; j+=x) {
	            if (data[j][i] != -1) {//有颜色输出
	                System.out.print("*");
	            } else {            //无颜色输出
	                System.out.print(" ");
	            }
	        }
	        System.out.println();//每行结束换行
	    }
	}

	public static void main(String[] args) {
	    getData("D:\\编程\\Java\\Java\\JavaSystem\\AddressBookSystem_ConsoleEdition\\timg.jpg");//读取图像资源
	}
	
}


