from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.
from core.models import GoodCategory

def category_list(request):
    categories = GoodCategory.objects.all()
    return render(request, 'categories.html', {'categories':categories})
