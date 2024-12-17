#в этой работе я использовал python, а не C++,
#поскольку в С++ нет аналога ORM, и команды для SQL
#приходится прописывать вручную
from sqlalchemy import create_engine, Column, Integer, String, ForeignKey
import sqlalchemy
from sqlalchemy.orm import sessionmaker, declarative_base
from sqlalchemy.ext.declarative import declarative_base
import os #для создания базы данных в конкретно этой папке

Base = declarative_base()

class ProductCategory(Base):
    __tablename__ = 'ProductCategory'

    id = Column(Integer, primary_key=True)
    name = Column(String(50), nullable=False)

class Product(Base):
    __tablename__ = 'Product'

    def to_dict(self):
        return {'id':self.id, 'name': self.name, 'price': self.price,
                'CategoryID': self.CategoryID}

    id = Column(Integer, primary_key=True)
    name = Column(String(50), nullable=False)
    price = Column(Integer, nullable=False)
    CategoryID = Column(Integer, ForeignKey('ProductCategory.id'), nullable=False)


current_dir = os.path.dirname(os.path.abspath(__file__))
db_path = os.path.join(current_dir, 'products.db')
engine = create_engine(f'sqlite:///{db_path}')
Base.metadata.create_all(engine)

# Создание сессии
Session = sessionmaker(bind=engine)
session = Session()


#ORM Создание категорий и продуктов.
def createCategory(name):
    try:
        # Попытка найти категорию с таким же именем
        existing_category = session.query(ProductCategory).filter_by(name=name).one()
        print(f"Категория с именем '{name}' уже существует. id: {existing_category.id}")
    except sqlalchemy.orm.exc.NoResultFound:
        # Если категория не найдена, создаем новую
        new_category = ProductCategory(name=name)
        session.add(new_category)
        session.commit()
        print(f"Категория '{name}' успешно создана. id: {new_category.id}")
    except sqlalchemy.exc.IntegrityError as e:
        # Обработка возможных других ошибок, связанных с целостностью данных
        print(f"Ошибка при создании категории: {e}")

def createProduct(name, price, cat_name):
    try:
        # Получаем категорию по имени
        cat = session.query(ProductCategory).filter_by(name=cat_name).one()
    except sqlalchemy.orm.exc.NoResultFound:
        #Если такой категории не существует
        print(f"Категории '{cat_name}' не существует")
        return None
    try:
        product = session.query(Product).filter_by(name=name).one()
        print(f"Продукт '{name}' уже существует")
    except sqlalchemy.orm.exc.NoResultFound:
        product = Product(name=name, price=price, CategoryID=cat.id)
        session.add(product)
        session.commit()
        print(f"Продукт '{product.name}' успешно создан. id: {product.id}")

#ORM Чтение продуктов по категориям
def readProductByCategory(cat_name):
    try:
        cat = session.query(ProductCategory).filter_by(name=cat_name).one()
        cat_products = session.query(Product).filter_by(CategoryID=cat.id).all()
        return [product.to_dict() for product in cat_products]
    except sqlalchemy.orm.exc.NoResultFound:
        print(f"Категории '{cat_name}' не существует")
        return []

#ORM Обновление категории у продукта
def updateProductCategory(name, cat_name):
    try:
        product = session.query(Product).filter_by(name=name).one()
        new_category = session.query(ProductCategory).filter_by(name=name).one()
        product.CategoryID = new_category.id
        session.commit()
        print(f"Теперь у продукта '{name}' категория '{cat_name}'")
    except sqlalchemy.orm.exc.NoResultFound as e:
        print(f"Продукт/категория не найдена: {e}")
    except Exception as e:
        print(f"При обновлении данных возникла ошибка: {e}")

#ORM Удаление
def deleteCategory(cat_name):
    try:
        category = session.query(ProductCategory).filter_by(name=cat_name).one()
    except sqlalchemy.orm.exc.NoResultFound as e:
        print(f"Категории '{cat_name}' не существует")
        return None
    session.query(Product).filter_by(CategoryID=category.id).delete()
    session.delete(category)
    session.commit()



createCategory("Bikes")
createCategory("Electronics")
createProduct("Duper-Bike", 500, "Bikes")
createProduct("BBC", 600, "Bikes")
createProduct("TV", 2000, "Electronics")
createProduct("Laptop", 3000, "Electronics")
createProduct("Bracelet", 100, "Accessoires")
print(readProductByCategory("Bikes"))
updateProductCategory("BBC", "Electronics")
print(readProductByCategory("Electronics"))
print(readProductByCategory("Bikes"))

session.close()
