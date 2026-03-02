#pylint: skip-file
import pygame
import sys

pygame.init()
pygame.display.set_caption("Test Window")
screen = pygame.display.set_mode((400, 500))
screen.fill((255,255,0))
pygame.display.update()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()