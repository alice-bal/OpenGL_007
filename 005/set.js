import * as THREE from "./include/three.module.js"
export default {
    init(data) {
        this.createRenderer(data.renderer);
        this.createCamera();
        this.createScene();
        this.createLight();
        this.update();
        
    },
    createRenderer(settings){

        if(this.renderer){
            this.renderer.domElement.parentNode.removeChild(this.renderer.domElement);
            this.renderer.dispose();
        }
        this.renderer = new THREE.WebGLRenderer(settings);
        settings.parent.appendChild(this.renderer.domElement);

        this.renderer.setSize(document.body.offsetWidth, document.body.offsetHeight);
    },
    createCamera(){
        this.camera = new THREE.PerspectiveCamera(
            75,
            document.body.offsetWidth/document.body.offsetHeight,
            0.1,
            1000
        )

        // this.camera.position.set(3,3,3);
        // this.camera.lookAt(0,0,0);
        this.camera.position.x = -5;
        this.camera.position.y = 10;
        this.camera.position.z = 25;
        this.camera.lookAt(0,0,0);
    },
    createScene(){
        this.scene = new THREE.Scene();
    },
    createLight(){
        // this.light1 = new THREE.DirectionalLight(0xffffff,.5);
        // this.scene.add(this.light1);
        // this.light1.position.set(5,5,5);
        this.spotLight = new THREE.SpotLight(0xeeeece);
        this.scene.add(this.spotLight);
        this.spotLight.position.set(1000, 1000, 1000);
        this.spotLight2 = new THREE.SpotLight(0xffffff);
        this.scene.add(this.spotLight2);
        this.spotLight2.position.set( -200, -200, -200);
    },
    update(){
        this.renderer.render(this.scene,this.camera);
        var that = this;
        requestAnimationFrame( ()=>{that.update();});
    }
}