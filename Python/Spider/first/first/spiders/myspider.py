# -*- coding: utf-8 -*-
import scrapy
from bs4 import BeautifulSoup


class MyspiderSpider(scrapy.Spider):
    name = 'myspider'
    allowed_domains = ['cuit.edu.cn']
    start_urls = ['https://www.cuit.edu.cn/DepartmentList?id=2']

    def parse(self, response):
        papers=response.xpath("//*[@id='DepartList']")
        for paper in papers:
        	title=papers.xpath("./li/a/text()").extract()
        	print(title)
        	


        	
