Некая крупная организация запустила новый проект: "Пошаговый тетрис". 

Ожидается, что проект будет сопровождаться много лет, им будет заниматься множество различных программистов и даже отдельных команд, заказчики смогут заказывать новые фичи. И вот у проекта появилась первая версия! Кнопки w, a, s и d позволяют управлять фигурами.

У нас в бэклоге лежат новые задачи:

* Заказчики хотят управлять формой фигур. Один заказчик будет описывать их в конфигурационных файлах, а другой требует, чтобы каждый раз появлялась фигура абсолютно случайной формы, в рамках заданных размеров.
* Необходимо организовать запись положения на доске в файл (после каждого хода), а также трансляцию событий игры через сетевые соединения для букмекеров. 
* Заказчик хочет управлять логикой удаления заполненных линий. В зависимости от конфигурации игры, линии будут удаляться:
	- как обычно
	- пока не заполнятся 3 линии, они не сгорают
	- вообще не будут удаляться
	- удаляются заполненные на 90 прц линии

Предложите свои изменения в проекте, которые позволят поддержать подобные доработки.

Задание:

* Что вы хотели бы изменить в текущей реализации? Почему?
* Предложите проработку изменений проекта для реализации фич из беклога и будущей поддержки решения.
* Ответ на задание необходимо оформить в виде текстового описания предлагаемых изменений.
* По-желанию можно проиллюстрировать ответ на задание можно любой удобной форме, например, или диаграмм (https://app.diagrams.net/), UML-схем, или в любом другом виде, в том числе и в виде кода. 
* Возможный вариант оформления можно увидеть здесь: <ссылка>

Оформление решения:
1. Сделайте приватный форк этого репозитория.
1. Дайте доступ к форку пользователю MyOfficeEdtCore.
1. Своё решение сделайте в ветке `solution`.
1. Создайте pull request из ветки `solution` в ветку `master` вашего приватного репозитория. 
1. Отправьте сслыку на pull request в форме регистрации на One Day Offer.