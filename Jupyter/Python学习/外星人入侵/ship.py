import pygame

class Ship():

    def __init__(self,ai_settings,screen) -> None:
        self.screen = screen
        self.ai_settings = ai_settings

        # load picture
        self.image = pygame.image.load('./images/ship.bmp')
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()

        # new ship position
        self.rect.centerx = self.screen_rect.centerx
        self.rect.bottom = self.screen_rect.bottom

        # store in center
        self.center = float(self.rect.centerx)

        # move flag
        self.moving_right = False
        self.moving_left = False
    
    def update(self):
        if self.moving_right:
            self.center += self.ai_settings.ship_speed_factor
        if self.moving_left:
            self.center -= self.ai_settings.ship_speed_factor

        self.rect.centerx = self.center

    def blitme(self):
        self.screen.blit(self.image,self.rect)