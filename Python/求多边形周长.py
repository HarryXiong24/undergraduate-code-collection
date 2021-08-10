import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Polygon:
    def __init__(self):
        self.vertices = []

    def add_point(self, point):
        self.vertices.append(point)

    def distance(self, point1, point2):
        return math.sqrt((point1.x - point2.x)**2 + (point1.y - point2.y)**2)

    def perimeter(self):
        perimeter = 0
        for i in range(len(self.vertices)):
            perimeter += self.distance(self.vertices[i], self.vertices[(i+1) % (len(self.vertices))])
        return perimeter

polygon = Polygon()
polygon.add_point(Point(1, 1))
polygon.add_point(Point(1, 2))
polygon.add_point(Point(3, 2))
polygon.add_point(Point(3, 1))

print(polygon.perimeter())
