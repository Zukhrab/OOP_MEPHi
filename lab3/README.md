
          Состояние класса - 
    Карта лото состоит из нескольких линий(напрмер от 1 до 10) по 9 клеток. Каждая линия описывается состояниями клеток игровой карты
    (пустая, свободная с числом, занятая с числом). Бочонок - занятая клетка с числом. Для описания клетки карты
    (состояние свободно, занято или число) целесообразно использовать структуру. Память под массив выделяется статически,
    во время компиляции, и задается массивом фиксированного размера. Числа в клетках получаются с помощью генератора
    случайных чисел(на одной линии 5 чисел)

    Протокол класса -
    Определяет возможности создания и инициализации экземпляров класса и правила их использования(методы класса). 

    Предусмотреть следующие возможности:

    1) пустой конструктор для инициализации экземпляров и массивов экземпляров класса по умолчаниюж;
    2) создание экземпляров класса с инициалиацией количеством линий, значения клеток которых определяется генератора
    случайных чисел;
    3) вывод экземпляров класса в выходной поток;
    4) выполнении операции "выбор боченка", т.е. получение нового числа из входного потока;
    5) проверить совподение(нет/есть) чисел карты "с бочонком"; при совпадении вернуть количество совпадений;
    6) получить состояние клетки карты(занято или свободно) по номеру линии и клетки в линии;
    7) "занять клетку карты(возможно несколько клеток в нескольких линиях" по значению "бочонка", т.е. утановить состояние
    занято;
    8) определить состояние клетки - есть ли на карте линия(линии) с полностью занятыми клетками;
    9) удвлить полностью занятые линии;
    10) выбрать "не выпавшие числа"(вернуть массив клеток без повоторений). 
