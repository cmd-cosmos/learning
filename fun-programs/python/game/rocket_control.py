#pylint: skip-file
import pygame
import sys
from pygame.locals import *

COLOR = (255,255,255)
WIDTH = 500
HEIGHT = 800

SURFACE = pygame.display.set_mode((WIDTH, HEIGHT))

FPS = pygame.time.Clock()
FPS.tick(60)



class RocketSprite(pygame.sprite.Sprite):
    def __init__(self) -> None:
        super().__init__()
        self.image = pygame.image.load("media/rocket-2.png")
        self.rect = self.image.get_rect()
        self.rect.center = (100, 100)

    def draw(self, surface):
        surface.blit(self.image, self.rect)

rocket = RocketSprite()
while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
        rocket.draw(SURFACE)
        pygame.display.update()

