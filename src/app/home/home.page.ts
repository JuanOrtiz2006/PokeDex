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
      const collections = ['fire', 'grass', 'poison', 'water', 'bug', 'flying', 'normal', 'fighting', 'ground', 'rock', 'ghost', 'steel', 'electric', 'psychic', 'ice', 'dragon', 'dark', 'fairy', 'unknown', 'shadow'];
      for (const collection of collections) {
        const typeDocRef = doc(this.db, 'PokeApi', collection);
        await setDoc(typeDocRef, { encender: false });
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
      // Apagar todos los LED antes de encender el correspondiente
      await this.apagarTodosLosLeds();

      for (const type of types) {
        const typeCollection = this.getTypeIndex(type);
        // Cambiar el estado del LED
        // Enviar el estado del LED a Firebase
        const typeDocRef = doc(this.db, 'PokeApi', typeCollection);
        await setDoc(typeDocRef, { encender: true });
      }
    } catch (error) {
      console.log(error);
    }
  }

  async apagarTodosLosLeds() {
    try {
      const collections = ['fire', 'grass', 'poison', 'water', 'bug', 'flying', 'normal', 'fighting', 'ground', 'rock', 'ghost', 'steel', 'electric', 'psychic', 'ice', 'dragon', 'dark', 'fairy', 'unknown', 'shadow'];
      for (const collection of collections) {
        const typeDocRef = doc(this.db, 'PokeApi', collection);
        await setDoc(typeDocRef, { encender: false });
      }
    } catch (error) {
      console.log(error);
    }
  }

  getTypeIndex(type: string): string {
    switch (type) {
      case 'fire': return 'fire';
      case 'grass': return 'grass';
      case 'poison': return 'poison';
      case 'water': return 'water';
      case 'bug': return 'bug';
      case 'flying': return 'flying';
      case 'normal': return 'normal';
      case 'fighting': return 'fighting';
      case 'ground': return 'ground';
      case 'rock': return 'rock';
      case 'ghost': return 'ghost';
      case 'steel': return 'steel';
      case 'electric': return 'electric';
      case 'psychic': return 'psychic';
      case 'ice': return 'ice';
      case 'dragon': return 'dragon';
      case 'dark': return 'dark';
      case 'fairy': return 'fairy';
      case 'unknown': return 'unknown';
      case 'shadow': return 'shadow';
      default: return '21'; // Tipo desconocido
    }
  }
}
