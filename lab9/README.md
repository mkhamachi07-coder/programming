Directoryy for lab 9

<img width="711" height="63" alt="image" src="https://github.com/user-attachments/assets/fd9d6f13-0e97-4d89-908d-32363accd901" />
так как перед тем как посмотреть статус я создал файл README через гитхаб и закоммитил, решил запулить эти изменения на локальный репозиторий, затем смотрим статус, говорит что мы на ветке main и коммитить нечего
++++++++++++++++++++++++++++++++++++++++++++++++++
<img width="675" height="383" alt="image" src="https://github.com/user-attachments/assets/1f65b4f8-9b5a-4da4-9e48-44cb6ff56de8" />
git log выглядит следующим образом. HEAD указывает на последний коммит в локальной ветке main (сам коммит говорит что в нем обновляется README) далее идут другие коммиты, здесь это коммиты с гитхаба(я там немного шаманил с файлами)
++++++++++++++++++++++++++++++++++++++++++++++++++
<img width="827" height="556" alt="image" src="https://github.com/user-attachments/assets/4f0b50e5-e9bc-4459-bfae-030f896acb23" />
создал файл sort.c с бабл сортировкой. Статус говорит что у нас есть не stage изменения. Добавляем этот файл в область stage с помощью add. теперь статус говорит что есть изменения которые можно коммитить. Коммитим файл. После этого статус говорит что есть изменения чтобы запушить на удаленный репо.
++++++++++++++++++++++++++++++++++++++++++++++++++
<img width="772" height="638" alt="image" src="https://github.com/user-attachments/assets/4e550f32-5055-42f5-af9f-e57036c1781f" />
с помощью нано добавил комментарий в файл с сортировкой. Статус говорит что есть не stage изменения. застейджим изменения файла и теперь статус говорит что есть изменения которые можно закоммитить. Далее добавляем еще изменения в файл с сортировкой (убрал предыдущий комментарий). Делаем коммит не добавляя изменения в stage. Статус говорит что появился новый коммит который можно отправить на удаленный репо (тот где мы добавляли комментариий) и есть не отслеживаемые изменения (те где мы убрали комментарий)
++++++++++++++++++++++++++++++++++++++++++++++++++
<img width="745" height="784" alt="image" src="https://github.com/user-attachments/assets/75d44cb3-1f40-4c32-a950-ecc084b027f4" />
лог выглядит вот так. HEAD указывает только на локальный main. Также есть два коммита (добавление файла и добавление комментария)
++++++++++++++++++++++++++++++++++++++++++++++++++
<img width="720" height="360" alt="image" src="https://github.com/user-attachments/assets/926fe1c5-37cd-4626-9913-c91b121e298e" />
Далее мы стейджим последние изменения (убираем комментарий) . Также пришлось запуллить изменения с удаленного репо потому что там закоммитил изменение README, перед тем как запушить коммиты с локального репо на удаленный.
++++++++++++++++++++++++++++++++++++++++++++++++++
<img width="704" height="465" alt="image" src="https://github.com/user-attachments/assets/8acdae69-d687-4366-857f-bdaf3c1bb3d7" />
ВЕТКИ: 
Создаем новую ветку mybranch с помощью checkout -b чтобы сразу переместиться на нее после создания. С помощью git branch проверяем текущую ветку на всякий случай. Статус при переключении на новую ветку изменит свой вывод на: На ветке mybranch, нечего коммитить.
создаем файл со своим именем, название файла file1.txtю Далее добавляем изменения в stage и коммитим изменения.
++++++++++++++++++++++++++++++++++++++++++++++++++
<img width="748" height="479" alt="image" src="https://github.com/user-attachments/assets/9accba98-3c1f-4881-b386-928729ef18ec" />
Используем git log --oneline --graph, чтобы увидеть, что наша ветка указывает на новый коммит.
++++++++++++++++++++++++++++++++++++++++++++++++++
<img width="827" height="315" alt="image" src="https://github.com/user-attachments/assets/7ac05e41-851b-40e7-9195-3979e98a4733" />
возвращаемся к ветке main и используем git log --oneline --graph. Теперь вывод показывает что мы на ветке main последний коммит это мердж локального репо и удаленного (специфика того что я делал скрины в README сразу на гитхабе и приходилось пуллить изменения перед пушем) Коммиты ветки mybranch нам не доступны.
++++++++++++++++++++++++++++++++++++++++++++++++++
<img width="861" height="295" alt="image" src="https://github.com/user-attachments/assets/a981a4e9-5431-4603-9bb5-dbde09c6446a" />
создаем файл file2.txt в ветке main ддобавляем и коммитим.git log --oneline --graph --all показывает что наша ветка указывает на новый коммит, и что теперь у двух веток разные коммиты
++++++++++++++++++++++++++++++++++++++++++++++++++
<img width="860" height="459" alt="image" src="https://github.com/user-attachments/assets/86a33519-9cc1-4088-aab4-590f71bfd19a" />
переключаемся на mybranch да file2 теперь пропал. git diff mybranch master покажет разницу между двумя ветками.
++++++++++++++++++++++++++++++++++++++++++++++++++
<img width="775" height="382" alt="image" src="https://github.com/user-attachments/assets/68b9955a-6beb-40ab-97e0-3697750bec17" />
так как текстовый док со скринами у меня уже на удаленном репо - пуллим изменения, чтобы он оказался и на локальном репо в ветке main. Далее пушим сначало ветку mybranch а потом и main
++++++++++++++++++++++++++++++++++++++++++++++++++
<img width="772" height="403" alt="image" src="https://github.com/user-attachments/assets/bb486192-ae3c-43e3-b02b-87347aff7035" />
NA 4

<img width="716" height="645" alt="image" src="https://github.com/user-attachments/assets/10da72d5-8735-4638-b4e0-ef8dc55d8961" />


<img width="637" height="575" alt="image" src="https://github.com/user-attachments/assets/4195f42b-4d9c-4d37-aed7-5635b2643485" />


<img width="724" height="305" alt="image" src="https://github.com/user-attachments/assets/be95e56e-48f9-469e-b9ed-a37480776271" />



<img width="412" height="262" alt="image" src="https://github.com/user-attachments/assets/4f4c084b-1253-40c4-9808-cb147007d942" />

<img width="740" height="243" alt="image" src="https://github.com/user-attachments/assets/6915fc08-352e-4e2c-91a8-730011e6b048" />


<img width="502" height="241" alt="image" src="https://github.com/user-attachments/assets/ff1f1a9b-864f-4244-8e5b-7e85d63e941c" />



<img width="795" height="461" alt="image" src="https://github.com/user-attachments/assets/510ce4a1-3d1b-4f02-b7fe-3073a5ec39b1" />


<img width="882" height="575" alt="image" src="https://github.com/user-attachments/assets/44c5afdd-83ec-4380-96a2-7d43d3ebda85" />



<img width="1091" height="495" alt="image" src="https://github.com/user-attachments/assets/ad4c9d91-5ceb-4023-9ff8-b774a29616d3" />



<img width="704" height="324" alt="image" src="https://github.com/user-attachments/assets/6e3be331-5a1a-43d6-ab16-ce1167e81f64" />


<img width="731" height="392" alt="image" src="https://github.com/user-attachments/assets/cddb95e2-5e3d-4969-85c5-318729115402" />


<img width="725" height="290" alt="image" src="https://github.com/user-attachments/assets/30091d61-32d6-4b0e-b021-99c02284bb90" />


<img width="1091" height="418" alt="image" src="https://github.com/user-attachments/assets/ad40752d-3c52-43b1-b0f1-4f03670f80fd" />


На 5
1
<img width="738" height="542" alt="image" src="https://github.com/user-attachments/assets/47bac025-dbcd-49e8-accc-241f4ac8189e" />
2
<img width="740" height="479" alt="image" src="https://github.com/user-attachments/assets/e4ef47ce-c0f4-4593-9f1b-876a81a66213" />
3
<img width="608" height="255" alt="image" src="https://github.com/user-attachments/assets/fb8fd943-c4a4-4148-b5ad-a11ed7aa77ae" />
4
<img width="746" height="473" alt="image" src="https://github.com/user-attachments/assets/b41a3861-a762-4eb2-bb7a-171218988f44" />
5
<img width="740" height="421" alt="image" src="https://github.com/user-attachments/assets/004f20c5-8a6c-4ff4-956b-7616d56ad446" />
6
<img width="751" height="481" alt="image" src="https://github.com/user-attachments/assets/104d8e54-86cf-4fb5-a796-8baf5b2bd13a" />
7
<img width="654" height="200" alt="image" src="https://github.com/user-attachments/assets/070ce076-de0c-40ff-996e-539428088036" />
8
<img width="753" height="469" alt="image" src="https://github.com/user-attachments/assets/963add28-f5e5-4129-8f3a-fa2e9bf95356" />
9

<img width="695" height="268" alt="image" src="https://github.com/user-attachments/assets/e08135fc-e1bb-4d24-99da-189258d23aa9" />

