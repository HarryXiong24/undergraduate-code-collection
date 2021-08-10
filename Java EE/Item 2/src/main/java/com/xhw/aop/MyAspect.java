package com.xhw.aop;

import org.aspectj.lang.annotation.*;
import org.springframework.stereotype.Component;

@Component
@Aspect
public class MyAspect {


    @Pointcut("execution(* com.xhw.entity.*.*(..))")
    private void pt1(){}

    /**
     * 前置通知
     */

    @Before("pt1()")
    public void beforeMessage() {
        System.out.println("这是前置通知");
    }

    @AfterReturning("pt1()")
    public void afterReturningMessage() {
        System.out.println("这是后置通知");
    }

    @AfterThrowing("pt1()")
    public void exceptionMessage() {
        System.out.println("这是异常通知");
    }
}
