import { Component } from '@angular/core';
import { APIServiceService } from '../Services/apiservice.service';
import { DomSanitizer } from '@angular/platform-browser';
import { Firestore, setDoc, doc } from '@angular/fire/firestore';

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage {

  constructor(private api: APIServiceService, private sanitizer: DomSanitizer, private db: Firestore) {
    this.initDatabase(); // Llama a la función para inicializar la base de datos al iniciar la aplicación
  }

  pokemonNombre!: string;
  pokemonNombre2!: string;
  pokemonType!: string;
  pokemonID!: number;
  pokemonID2!: number;
  pokemonImagen: any;
  type: any;
  encender = false; // Inicializar el estado del LED

  async initDatabase() {
    try {
      // Inicializa todas las colecciones de tipos de Pokémon en la base de datos con el estado "false"
      const collections = ['Tipo', 'Tipo2', 'Tipo3', 'Tipo4', 'Tipo5', 'Tipo6', 'Tipo7', 'Tipo8', 'Tipo9', 'Tipo10', 'Tipo11', 'Tipo12', 'Tipo13', 'Tipo14', 'Tipo15', 'Tipo16', 'Tipo17', 'Tipo18', 'Tipo19', 'Tipo20'];
      for (const collection of collections) {
        const typeDocRef = doc(this.db, 'PokeApi', collection);
        await setDoc(typeDocRef, { [collection.toLowerCase()]: false });
      }
    } catch (error) {
      console.log(error);
    }
  }

  getPokemonData(nameOrId: string | number) {
    try {
      let apiCall;
      if (typeof nameOrId === 'string') {
        apiCall = this.api.getPokemonName(nameOrId);
      } else {
        apiCall = this.api.getPokemonID(nameOrId);
      }

      apiCall.subscribe((response => {
        this.pokemonNombre2 = response.name;
        this.pokemonID2 = response.id;

        // Obtener los tipos del Pokémon
        const types = response.types.map((typeInfo: any) => typeInfo.type.name);
        this.pokemonType = types.join(',');

        // Obtener la imagen del Pokémon
        const imgUrl = 'https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/' + this.pokemonID2 + '.png';
        this.pokemonImagen = this.sanitizer.bypassSecurityTrustUrl(imgUrl);

        // Llamar a la función tipo() para enviar el tipo de Pokémon a Firebase
        this.tipo(types);
      }));
    } catch (error) {
      console.log(error);
    }
  }

  async tipo(types: string[]) {
    try {
      for (const type of types) {
        const typeCollection = 'Tipo' + this.getTypeIndex(type);
        // Cambiar el estado del LED
        // Enviar el estado del LED a Firebase
        const typeDocRef = doc(this.db, 'PokeApi', typeCollection);
        await setDoc(typeDocRef, { [type.toLowerCase()]: true });
      }
    } catch (error) {
      console.log(error);
    }
  }

  getTypeIndex(type: string): string {
    switch (type) {
      case 'fire': return '1';
      case 'grass': return '2';
      case 'poison': return '3';
      case 'water': return '4';
      case 'bug': return '5';
      case 'flying': return '6';
      case 'normal': return '7';
      case 'fighting': return '8';
      case 'ground': return '9';
      case 'rock': return '10';
      case 'ghost': return '11';
      case 'steel': return '12';
      case 'electric': return '13';
      case 'psychic': return '14';
      case 'ice': return '15';
      case 'dragon': return '16';
      case 'dark': return '17';
      case 'fairy': return '18';
      case 'unknown': return '19';
      case 'shadow': return '20';
      default: return '21'; // Tipo desconocido
    }
  }
}