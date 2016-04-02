/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.insalyon.ovicente.td.jpa;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

/**
 *
 * @author ovicente
 */
public class Main 
{
    public static void main(String[] args)
    {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("DatabaseTD");
        EntityManager em = emf.createEntityManager();
        String nom = "LePersistant";
        String prenom = "Maurice";
        int age = 12;
        Personne p = new Personne( nom, prenom, age);
        int id = 1;
        em.getTransaction().begin();
        em.persist(p);
        em.getTransaction().commit();
        em.close();
        emf.close();
    }
}
