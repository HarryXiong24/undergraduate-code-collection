package com.wjy.ulitis;

import java.beans.IntrospectionException;
import java.beans.Introspector;
import java.beans.PropertyDescriptor;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.List;
import java.util.Set;

public class jsonn {
        public static String objectTojson(Object obj) {
            StringBuilder json = new StringBuilder();
            if (obj == null) {
                json.append("\"\"");
            } else if (obj instanceof String || obj instanceof Integer || obj instanceof Float
                    || obj instanceof Boolean || obj instanceof Short || obj instanceof Double
                    || obj instanceof Long || obj instanceof BigDecimal || obj instanceof BigInteger
                    || obj instanceof Byte) {
                json.append("\"").append(stringTojson(obj.toString())).append("\"");
            } else if (obj instanceof Object[]) {
                json.append(arrayTojson((Object[]) obj));
            } else if (obj instanceof List) {
                json.append(listToJson((List<?>) obj));
            }  else if (obj instanceof Set) {
                json.append(setTojson((Set<?>) obj));
            } else {
                json.append(objectToJson(obj));
            }
            return json.toString();
        }
        /**
         * @param object
         *             任意对象
         * @return java.lang.String
         */
        public static String objectToJson(Object object) {
            StringBuilder json = new StringBuilder();
            if (object == null) {
                json.append("\"\"");
            } else if (object instanceof String || object instanceof Integer) {
                json.append("\"").append(object.toString()).append("\"");
            } else {
                json.append(beanToJson(object));
            }
            return json.toString();
        }

        /**
         * 功能描述:传入任意一个 javabean 对象生成一个指定规格的字符串
         *
         * @param bean
         *             bean对象
         * @return String
         */
        public static String beanToJson(Object bean) {
            StringBuilder json = new StringBuilder();
            json.append("{");
            PropertyDescriptor[] props = null;
            try {
                props = Introspector.getBeanInfo(bean.getClass(), Object.class).getPropertyDescriptors();
            } catch (IntrospectionException e) {}
            if (props != null) {
                for (int i = 0; i < props.length; i++) {
                    try {
                        String name = objectTojson(props[i].getName());
                        String value = objectTojson(props[i].getReadMethod().invoke(bean));
                        json.append(name);
                        json.append(":");
                        json.append(value);
                        json.append(",");
                    } catch (Exception e) {}
                }
                json.setCharAt(json.length() - 1, '}');
            } else {
                json.append("}");
            }
            return json.toString();
        }

        /**
         * 功能描述:通过传入一个列表对象,调用指定方法将列表中的数据生成一个JSON规格指定字符串
         *
         * @param list
         *             列表对象
         * @return java.lang.String
         */
        public static String listToJson(List<?> list) {
            StringBuilder json = new StringBuilder();
            json.append("[");
            if (list != null && list.size() > 0) {
                for (Object obj : list) {
                    json.append(objectTojson(obj));
                    json.append(",");
                }
                json.setCharAt(json.length() - 1, ']');
            } else {
                json.append("]");
            }
            return json.toString();
        }

        public static String arrayTojson(Object[] array) {
            StringBuilder json = new StringBuilder();
            json.append("[");
            if (array != null && array.length > 0) {
                for (Object obj : array) {
                    json.append(objectTojson(obj));
                    json.append(",");
                }
                json.setCharAt(json.length() - 1, ']');
            } else {
                json.append("]");
            }
            return json.toString();
        }
    public static String setTojson(Set<?> set) {
        StringBuilder json = new StringBuilder();
        json.append("[");
        if (set != null && set.size() > 0) {
            for (Object obj : set) {
                json.append(objectTojson(obj));
                json.append(",");
            }
            json.setCharAt(json.length() - 1, ']');
        } else {
            json.append("]");
        }
        return json.toString();
    }

    public static String stringTojson(String s) {
        if (s == null)
            return "";
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            switch (ch) {
                case '"':
                    sb.append("\\\"");
                    break;
                case '\\':
                    sb.append("\\\\");
                    break;
                case '\b':
                    sb.append("");
                    break;
                case '\f':
                    sb.append("");
                    break;
                case '\n':
                    sb.append("");
                    break;
                case '\r':
                    sb.append("");
                    break;
                case '\t':
                    sb.append("");
                    break;
                default:
                    if (ch >= '\u0000' && ch <= '\u001F') {
                        String ss = Integer.toHexString(ch);
                        sb.append("");
                        for (int k = 0; k < 4 - ss.length(); k++) {
                            sb.append('0');
                        }
                        sb.append(ss.toUpperCase());
                    } else {
                        sb.append(ch);
                    }
            }
        }
        return sb.toString();
    }
}

