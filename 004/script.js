const canvas = document.querySelector("canvas");    // первый элемент канвас
const context = canvas.getContext("2d");            // контекст рисования на холсте: 2d

canvas.width = 1271;                                // размеры видимой области
canvas.height = 649;

const image = new Image();                          // создаем и привязываем изображение
image.src = "pizza.png";

let x = canvas.width * Math.random();   // Math.random() возвращает число из диапазона [0,1)
let y = canvas.height * Math.random();  // let - область видимости внутри блока
let n = 10;                             // число объектов
let pizza = [];                         // пустой массив

function InitPizza ()                               // создаем n элементов
{
    for ( let i = 0; i < n; i++ )
    {
        pizza.push                                      // добавляем элемент в конец
        ({
            x: (canvas.width - 400) * Math.random(),    // координаты 
            y: (canvas.height- 170) * Math.random(),   
            sx: 5 * Math.random(),                      // значение сдвига
            sy: 5 * Math.random(),
        })
    }
}

function move()                                    // двигаем n элементов
{
    for ( let value of pizza )           // обход всех элементов массива pizza  
    {                   
        value.x -= value.sx             // уменьшаем координаты на значение сдвига             
        value.y -= value.sy

        if( value.x > canvas.width - 200 || value.x < 0 ) 
            value.sx *= -1;             // при достижении границ меняем направление
        
        if( value.y > canvas.height - 90 || value.y < 0 )
            value.sy *= -1;
    }
}

function draw()                                   // очищаем и рисуем
{
    context.clearRect( 0, 0, canvas.width, canvas.height );      // очистка экрана в границах w, h
    for ( let value of pizza )
        context.drawImage( image, value.x, value.y, 200, 100 );  // рисуем на x y
        // context.drawImage( image, value.x, value.y );         // без масштабирования
}

function run() {
    requestAnimationFrame(()=>      // планируем перерисовку на следующем кадре
    {
        move()                      // функции будут вызваны перед перерисовкой
        draw()
        run()
    })
}

image.onload = () =>                // запуск после загрузки изображения
{
    InitPizza ()
    run()
}