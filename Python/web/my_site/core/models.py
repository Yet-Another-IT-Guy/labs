from django.db import models

# Create your models here.

class Shop(models.Model):
    name = models.CharField(max_length=255)
    contacts = models.TextField(max_length=1024)
    owner = models.ManyToManyField('Owner')
    good = models.ManyToManyField('Good', through='ShopGoodPrice') 
class Owner(models.Model):
    first_name = models.CharField(max_length=64)
    last_name = models.CharField(max_length=64)

class Good(models.Model):
    name = models.CharField(max_length=255)
    category = models.ForeignKey('GoodCategory')

class ShopGoodPrice(models.Model):
    shop = models.ForeignKey(Shop)
    good = models.ForeignKey(Good)
    price = models.DecimalField(max_digits=10, decimal_places=2)

class GoodCategory(models.Model):
    name = models.CharField(max_length=255)    
