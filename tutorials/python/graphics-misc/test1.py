#pylint: skip-file
import pygame
import sys

pygame.init()
pygame.display.set_mode((500, 200))

class Ball:
    def __init__(self, radius) -> None:
        self.radius = radius
    
    def draw(self):
        pass

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        pygame.display.update()