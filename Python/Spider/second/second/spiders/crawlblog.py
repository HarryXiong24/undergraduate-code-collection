# -*- coding: utf-8 -*-
import scrapy


class CrawlblogSpider(scrapy.Spider):
    name = 'crawlblog'
    allowed_domains = ['cnblogs.com']
    start_urls = ['https://www.cnblogs.com/qiyeboy/category/901764.html']

    def parse(self, response):
        papers=response.xpath("//*[@class='entrylistItem']")
        print(papers)
        # for paper in papers:
        # 	title=paper.xpath(".//*[@calss='entrylistPosttitle']/a/text()").extract()[0]
        # 	url=paper.xpath(".//*[@calss='entrylistPosttitle']/a/@href").extract()[0]
        # 	content=paper.xpath(".//*[@calss='entrylistPostSummary']/div/text()").extract()[0]
        # 	time=paper.xpath(".//*[@calss='entrylistItemPostDesc']/a[@title='permalink']/text()").extract()[0]
        # 	print(title,url,content,time)