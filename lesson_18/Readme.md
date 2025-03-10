# Проект CoffeeMachine

## Опис
Цей проект імітує функціональність кавомашини, реалізуючи такі реалістичні механіки, як

- **Приготування кави**: Еспресо, капучино та інші напої.
- **Управління резервуаром**: Контейнери для води, молока та кавових зерен.
- **Основні стани**: Використання шаблону стану для різних станів машини.
- **Настроювані напої**: Легко розширюється для нових напоїв, таких як різні чаї, какао або види кави.
- **Функції обслуговування**: Нагадування про очищення та сплячий режим (в розробці).

## Функції

### Доступні напої
1. Еспресо
2. Капучино
3. Чорний чай
4. Зелений чай

### Основні механіки
- **Резервуар з водою**: Відстежує рівень води та підказує, коли її потрібно поповнити.
- **Резервуар молока**: Перевіряє кількість молока та контроль якості молока.
- **Контейнер для кавових зерен**: Забезпечує наявність достатньої кількості кавових зерен, виконує помел і видаляє використані зерна в окрему емність.
- **Нагадування про очищення**: Відстежує кількість приготованих напоїв і сповіщає користувача про необхідність очищення всієї машини.

### Розширюваність
- Використовуйте базовий клас `DrinkProgram` для додавання нових напоїв з мінімальними зусиллями.
- Спільна логіка для резервуарів і контейнерів абстрагована через поліморфні інтерфейси.
- Високомодульний дизайн з використанням об'єктно-орієнтованих принципів.

## Встановлення
1. Клонуйте сховище:
   ```bash
   git clone <repository-url>
   ```
2. Перейдіть до каталогу проекту та запустіть `.sln` файл.
3. `F5` запустить та виведе програму в консолі програмного забезпечення в якому ви запустили проект.
4. Дотримуйтесь екранного меню, щоб вибрати напої або керувати кавоваркою.

### Параметри меню
- **Вибір напоїв**: Виберіть один з доступних напоїв.
- **Керування машиною**: Поповнення резервуарів, очищення машини або перевірка стану машини.

## Структура коду

### Основні класи
- **`CoffeeMachine`**: Керує загальною роботою кавомашини.
- **`DrinkProgram`**: Базовий клас для напоїв, розширений класами `Coffee`, `Tea` та їх специфічними типами.
- **`Reservoir`**: Абстрактний базовий клас для `WaterReservoir` та `MilkReservoir`.
- **`CoffeeGrainsContainer`**: Відповідає за управління кавовими зернами.
- **`CoffeeMachineState`**: Реалізує паттерн стану для поведінки машини.

### Шаблон стану
- **StateIdle**: Стан за замовчуванням, очікує на взаємодію з користувачем.
- **StateDrinkSelection**: Обробляє логіку вибору та приготування напоїв.
- **StateReseivoir**: Підказки щодо очищення та дозаправки.

## Приклад робочого процесу
1. **Запуск машини**: 
   - Машина ініціалізується у `StateIdle`.
2. **Вибір напою**: 
   - Виберіть еспресо, капучино або інший напій.
   - Система перевіряє резервуари та контейнер для зерен.
3. **Приготування напою**: 
   - Імітує процес приготування за допомогою анімації та таймерів.
4. **Перевірка резервуарів води, молока та зерен.** 
5. **Після певної кількості напоїв машина запропонує очистити її.**

## Розширення системи
### Додавання нового напою
1. Створіть новий підклас `DrinkProgram` (наприклад, `Cocoa`).
2. Реалізуйте специфічну логіку приготування у перевизначеному методі `prepare()`.
3. Додайте новий напій до `initDefaultDrinks()` у `CoffeeMachine`.

### Додавання нового типу резервуара
1. Створіть новий підклас `Reservoir` (наприклад, `SyrupReservoir`).
2. Визначте специфічну поведінку для методів `check()`, `fill()` та інших.
3. Інтегрувати його у логіку `CoffeeMachine`.

## Майбутні вдосконалення
- **Контроль температури**: Налаштування температури води для певних напоїв.
- **Профілі користувачів**: Збереження та повторне використання улюблених конфігурацій напоїв.
- **Інтеграція з мобільними додатками**: Дозволяє дистанційно керувати машиною.

