import Viewer from "./set.js";
import * as THREE from "./include/three.module.js";

export default class {
    constructor() {
        Viewer.init(
            {
                renderer:{
                    parent:document.body,
                    antialias: true,
                    alpha: true,
                }
            }

        );
        this.createObject();
    }
    createObject() {

//  СЦЕНА
        
        // PlaneGeometry( width, height, widthSegments, heightSegments )
        //      width — ширина по оси x
        //      height — высота по оси y
        //      widthSegments — кол-во сегментов по x (доп. параметр, по умолчанию 1).
        //      heightSegments — аналонично по y
        
        const loader = new THREE.TextureLoader();

        this.planeGeometry = new THREE.PlaneGeometry( 200, 40, 10, 10);             // определяем форму
        this.planeMaterial = new THREE.MeshBasicMaterial({                          // внешний вид 
            map: loader.load( 'img/sand.jpg' )});        
        this.plane = new THREE.Mesh( this.planeGeometry, this.planeMaterial );      // совмещаем и стороим объект
        
        Viewer.scene.add( this.plane );                                             // добавляем на сцену
        this.plane.rotation.x = -0.3 * Math.PI;                                     // поворот   
        this.plane.position.x = 15;                                                 // координаты
        this.plane.position.y =-10;
        this.plane.position.z = 0;

//  ПИРАМИДА СЛЕВА

        this.coneGeometry = new THREE.ConeGeometry( 8, 9, 4 );
        this.coneMaterial = new THREE.MeshBasicMaterial({
            map: loader.load('img/stone.jpg')});
        this.cone = new THREE.Mesh(this.coneGeometry, this.coneMaterial);
        Viewer.scene.add(this.cone);
        this.cone.rotation.x = -0.05 * Math.PI;
        this.cone.rotation.y = -0.01 * Math.PI;
        this.cone.position.x = -4;
        this.cone.position.y = 3;
        this.cone.position.z = 0;

// ПИРАМИДА ПОСЕРЕДИНЕ

        this.cone2Geometry = new THREE.ConeGeometry( 9, 10, 4 );
        this.cone2Material = new THREE.MeshBasicMaterial({
            map: loader.load('img/stone.jpg')});
        this.cone2 = new THREE.Mesh(this.cone2Geometry, this.cone2Material);
        Viewer.scene.add(this.cone2);
        this.cone2.rotation.x = -0.05 * Math.PI;
        this.cone2.rotation.y = -0.05 * Math.PI;
        this.cone2.position.x = 10;
        this.cone2.position.y = 5;
        this.cone2.position.z = -3;

// ПИРАМИДА СПРАВА 

        this.cone3Geometry = new THREE.ConeGeometry( 8, 8, 4);
        this.cone3Material = new THREE.MeshBasicMaterial({
            map: loader.load('img/stone.jpg')});
        this.cone3 = new THREE.Mesh(this.cone3Geometry, this.cone3Material);
        Viewer.scene.add(this.cone3);
        this.cone3.rotation.x = -0.05 * Math.PI;
        this.cone3.rotation.y = -0.1 * Math.PI;
        this.cone3.position.x = 25;
        this.cone3.position.y = 5;
        this.cone3.position.z = 0;
    }
}