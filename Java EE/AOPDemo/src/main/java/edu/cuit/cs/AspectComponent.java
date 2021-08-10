package edu.cuit.cs;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;
import org.springframework.stereotype.Component;

    /**
     * aop组件
     */
    @Aspect
    @Component
    public class AspectComponent {

        @Pointcut("execution(* edu.cuit.cs.UserService.*(..))")
        public void pointCut(){
        }

        @Before("execution(public * edu.cuit.cs.*Service*.*(..))")
        public void before(JoinPoint joinPoint) {

            System.out.println("before aspect executed"+joinPoint.toString());
        }

        @After("pointCut()")
        public void after(JoinPoint joinPoint) {

            System.out.println("after aspect executed:"+joinPoint.toString());
        }


        @AfterReturning(pointcut = "pointCut()", returning = "returnVal")
        public void afterReturning(JoinPoint joinPoint, Object returnVal) {
            System.out.println("afterReturning executed, return result is "
                    + returnVal +joinPoint.toString());
        }

        @Around("pointCut()")
        public void around(ProceedingJoinPoint pjp) throws Throwable {
            System.out.println("around start");
            try {
                pjp.proceed();
            } catch (Throwable ex) {
                System.out.println("error in around");
                throw ex;
            }
            System.out.println("around end");
        }

        @AfterThrowing(pointcut = "pointCut()", throwing = "error")
        public void afterThrowing(JoinPoint joinPoint, Throwable error) {
            System.out.println("error:" + error+joinPoint.toString());
        }
    }
