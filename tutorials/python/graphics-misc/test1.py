#pylint: skip-file
import pygame
import sys
import random

pygame.init()
pygame.display.set_caption("Test Window")
screen = pygame.display.set_mode((400, 500))
screen.fill((255,255,255))
pygame.display.update()
rect = pygame.Rect(10, 10, 20, 20)

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        pygame.draw.rect(screen, color="red", rect=rect)
        pygame.display.flip()
        pygame.display.update()