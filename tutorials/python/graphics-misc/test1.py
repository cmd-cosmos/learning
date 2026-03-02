#pylint: skip-file
import pygame
import sys
import random

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
        screen.fill((random.randint(0,255), random.randint(0,255), random.randint(0,255)))
        pygame.display.update()