
class Player():
    def __init__(self, hp, power):
        self.hp = hp
        self.power = power

    def attack(self, enemy):
        enemy.hp -= self.power


p1, p2 = Player(70, 40), Player(100, 50)

print("first: ", p1.hp)

p2.attack(p1)

print("second: ", p1.hp)